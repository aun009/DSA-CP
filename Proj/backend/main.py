from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
import sqlite3
import pandas as pd
import os
from datetime import timedelta

app = FastAPI(title="Lumina Analytics API")

# CORS
app.add_middleware(
    CORSMiddleware,
    allow_origins=["http://localhost:3000"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

DB_PATH = os.path.join(os.path.dirname(__file__), "lumina.db")

def get_db_connection():
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    return conn

@app.get("/")
def read_root():
    return {"message": "Welcome to Lumina Analytics API"}

@app.get("/api/stats")
def get_stats():
    conn = get_db_connection()
    try:
        # Total Sales
        total_sales = pd.read_sql("SELECT SUM(total_amount) FROM transactions", conn).iloc[0, 0]
        
        # Total Orders
        total_orders = pd.read_sql("SELECT COUNT(*) FROM transactions", conn).iloc[0, 0]
        
        # Total Customers
        total_customers = pd.read_sql("SELECT COUNT(*) FROM users", conn).iloc[0, 0]
        
        # Avg Order Value
        avg_order_value = total_sales / total_orders if total_orders else 0
        
        return {
            "total_sales": round(float(total_sales), 2),
            "total_orders": int(total_orders),
            "total_customers": int(total_customers),
            "avg_order_value": round(float(avg_order_value), 2)
        }
    finally:
        conn.close()

@app.get("/api/sales-history")
def get_sales_history():
    conn = get_db_connection()
    try:
        query = """
            SELECT date(date) as date, SUM(total_amount) as sales
            FROM transactions
            GROUP BY date(date)
            ORDER BY date(date) ASC
        """
        df = pd.read_sql(query, conn)
        return df.to_dict(orient="records")
    finally:
        conn.close()

@app.get("/api/recent-transactions")
def get_recent_transactions():
    conn = get_db_connection()
    try:
        query = """
            SELECT t.transaction_id, u.name as user, p.name as product, t.total_amount, t.date
            FROM transactions t
            JOIN users u ON t.user_id = u.user_id
            JOIN products p ON t.product_id = p.product_id
            ORDER BY t.date DESC
            LIMIT 5
        """
        df = pd.read_sql(query, conn)
        return df.to_dict(orient="records")
    finally:
        conn.close()

@app.get("/api/customers")
def get_customer_segments():
    conn = get_db_connection()
    try:
        # Get RFM data
        query = """
            SELECT 
                u.user_id,
                u.name,
                COUNT(t.transaction_id) as frequency,
                SUM(t.total_amount) as monetary,
                MAX(t.date) as last_purchase
            FROM users u
            LEFT JOIN transactions t ON u.user_id = t.user_id
            GROUP BY u.user_id
        """
        df = pd.read_sql(query, conn)
        
        # Simple Segmentation Logic
        def segment_customer(row):
            if row['monetary'] > 1000 and row['frequency'] > 10:
                return 'VIP'
            elif row['frequency'] > 5:
                return 'Loyal'
            elif pd.isnull(row['last_purchase']):
                return 'Inactive'
            else:
                return 'Regular'
                
        df['segment'] = df.apply(segment_customer, axis=1)
        
        # Group by segment for chart
        segment_counts = df['segment'].value_counts().reset_index()
        segment_counts.columns = ['name', 'value']
        
        return {
            "segments": segment_counts.to_dict(orient="records"),
            "top_customers": df.sort_values('monetary', ascending=False).head(5).to_dict(orient="records")
        }
    finally:
        conn.close()

@app.get("/api/forecast")
def get_sales_forecast():
    conn = get_db_connection()
    try:
        # Get daily sales
        query = """
            SELECT date(date) as date, SUM(total_amount) as sales
            FROM transactions
            GROUP BY date(date)
            ORDER BY date(date) ASC
        """
        df = pd.read_sql(query, conn)
        df['date'] = pd.to_datetime(df['date'])
        df['day_ordinal'] = df['date'].map(pd.Timestamp.toordinal)
        
        # Simple Linear Regression
        from sklearn.linear_model import LinearRegression
        import numpy as np
        
        X = df['day_ordinal'].values.reshape(-1, 1)
        y = df['sales'].values
        
        model = LinearRegression()
        model.fit(X, y)
```python
from fastapi import FastAPI, HTTPException
from fastapi.middleware.cors import CORSMiddleware
import sqlite3
import pandas as pd
import os
from datetime import timedelta

app = FastAPI(title="Lumina Analytics API")

# CORS
app.add_middleware(
    CORSMiddleware,
    allow_origins=["http://localhost:3000"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

DB_PATH = os.path.join(os.path.dirname(__file__), "lumina.db")

def get_db_connection():
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    return conn

@app.get("/")
def read_root():
    return {"message": "Welcome to Lumina Analytics API"}

@app.get("/api/stats")
def get_stats():
    conn = get_db_connection()
    try:
        # Total Sales
        total_sales = pd.read_sql("SELECT SUM(total_amount) FROM transactions", conn).iloc[0, 0]
        
        # Total Orders
        total_orders = pd.read_sql("SELECT COUNT(*) FROM transactions", conn).iloc[0, 0]
        
        # Total Customers
        total_customers = pd.read_sql("SELECT COUNT(*) FROM users", conn).iloc[0, 0]
        
        # Avg Order Value
        avg_order_value = total_sales / total_orders if total_orders else 0
        
        return {
            "total_sales": round(float(total_sales), 2),
            "total_orders": int(total_orders),
            "total_customers": int(total_customers),
            "avg_order_value": round(float(avg_order_value), 2)
        }
    finally:
        conn.close()

@app.get("/api/sales-history")
def get_sales_history():
    conn = get_db_connection()
    try:
        query = """
            SELECT date(date) as date, SUM(total_amount) as sales
            FROM transactions
            GROUP BY date(date)
            ORDER BY date(date) ASC
        """
        df = pd.read_sql(query, conn)
        return df.to_dict(orient="records")
    finally:
        conn.close()

@app.get("/api/recent-transactions")
def get_recent_transactions():
    conn = get_db_connection()
    try:
        query = """
            SELECT t.transaction_id, u.name as user, p.name as product, t.total_amount, t.date
            FROM transactions t
            JOIN users u ON t.user_id = u.user_id
            JOIN products p ON t.product_id = p.product_id
            ORDER BY t.date DESC
            LIMIT 5
        """
        df = pd.read_sql(query, conn)
        return df.to_dict(orient="records")
    finally:
        conn.close()

@app.get("/api/customers")
def get_customer_segments():
    conn = get_db_connection()
    try:
        # Get RFM data
        query = """
            SELECT 
                u.user_id,
                u.name,
                COUNT(t.transaction_id) as frequency,
                SUM(t.total_amount) as monetary,
                MAX(t.date) as last_purchase
            FROM users u
            LEFT JOIN transactions t ON u.user_id = t.user_id
            GROUP BY u.user_id
        """
        df = pd.read_sql(query, conn)
        
        # Simple Segmentation Logic
        def segment_customer(row):
            if row['monetary'] > 1000 and row['frequency'] > 10:
                return 'VIP'
            elif row['frequency'] > 5:
                return 'Loyal'
            elif pd.isnull(row['last_purchase']):
                return 'Inactive'
            else:
                return 'Regular'
                
        df['segment'] = df.apply(segment_customer, axis=1)
        
        # Group by segment for chart
        segment_counts = df['segment'].value_counts().reset_index()
        segment_counts.columns = ['name', 'value']
        
        return {
            "segments": segment_counts.to_dict(orient="records"),
            "top_customers": df.sort_values('monetary', ascending=False).head(5).to_dict(orient="records")
        }
    finally:
        conn.close()

@app.get("/api/forecast")
def get_sales_forecast():
    conn = get_db_connection()
    try:
        # Get daily sales
        query = """
            SELECT date(date) as date, SUM(total_amount) as sales
            FROM transactions
            GROUP BY date(date)
            ORDER BY date(date) ASC
        """
        df = pd.read_sql(query, conn)
        df['date'] = pd.to_datetime(df['date'])
        df['day_ordinal'] = df['date'].map(pd.Timestamp.toordinal)
        
        # Simple Linear Regression
        from sklearn.linear_model import LinearRegression
        import numpy as np
        
        X = df['day_ordinal'].values.reshape(-1, 1)
        y = df['sales'].values
        
        model = LinearRegression()
        model.fit(X, y)
        
        # Predict next 30 days
        last_day = df['day_ordinal'].max()
        future_days = np.array([last_day + i for i in range(1, 31)]).reshape(-1, 1)
        predictions = model.predict(future_days)
        
        future_dates = [df['date'].max() + timedelta(days=i) for i in range(1, 31)]
        
        forecast_data = []
        for date, sales in zip(future_dates, predictions):
            forecast_data.append({
                "date": date.strftime('%Y-%m-%d'),
                "sales": round(float(sales), 2),
                "type": "forecast"
            })
            
        return forecast_data
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
    finally:
        conn.close()

# Simple JSON store for admin profile
PROFILE_FILE = os.path.join(os.path.dirname(__file__), "profile.json")

def get_profile_data():
    if not os.path.exists(PROFILE_FILE):
        return {"name": "Admin User", "email": "admin@lumina.ai"}
    try:
        import json
        with open(PROFILE_FILE, 'r') as f:
            return json.load(f)
    except:
        return {"name": "Admin User", "email": "admin@lumina.ai"}

def save_profile_data(data):
    import json
    with open(PROFILE_FILE, 'w') as f:
        json.dump(data, f)

from pydantic import BaseModel

class ProfileUpdate(BaseModel):
    name: str
    email: str

@app.get("/api/profile")
def get_profile():
    return get_profile_data()

@app.post("/api/profile")
def update_profile(profile: ProfileUpdate):
    save_profile_data(profile.dict())
    return {"status": "success", "profile": profile}

@app.post("/api/regenerate")
def regenerate_data():
    try:
        # Import here to avoid circular imports if any, and to keep main startup fast
        from backend.data_generator import generate_data
        from backend.database import init_db
        
        # Regenerate CSVs
        generate_data()
        
        # Reload Database
        init_db()
        
        return {"status": "success", "message": "Data regenerated and database reloaded successfully"}
    except Exception as e:
        raise HTTPException(status_code=500, detail=str(e))
    finally:
        # This finally block is present in the provided snippet,
        # but there's no 'conn' object opened in this function.
        # Keeping it as per instruction to make faithful edits.
        pass 
```
