import sqlite3
import pandas as pd
import os

DB_PATH = os.path.join(os.path.dirname(__file__), "lumina.db")
DATA_DIR = os.path.join(os.path.dirname(os.path.dirname(__file__)), "data")

def init_db():
    print("Initializing database...")
    conn = sqlite3.connect(DB_PATH)
    
    # Load CSVs
    try:
        users = pd.read_csv(os.path.join(DATA_DIR, 'users.csv'))
        products = pd.read_csv(os.path.join(DATA_DIR, 'products.csv'))
        transactions = pd.read_csv(os.path.join(DATA_DIR, 'transactions.csv'))
        
        # Write to SQLite
        users.to_sql('users', conn, if_exists='replace', index=False)
        products.to_sql('products', conn, if_exists='replace', index=False)
        transactions.to_sql('transactions', conn, if_exists='replace', index=False)
        
        print("Database populated successfully.")
        
        # Verify
        cursor = conn.cursor()
        cursor.execute("SELECT count(*) FROM transactions")
        count = cursor.fetchone()[0]
        print(f"Total transactions: {count}")
        
    except Exception as e:
        print(f"Error initializing database: {e}")
    finally:
        conn.close()

if __name__ == "__main__":
    init_db()
