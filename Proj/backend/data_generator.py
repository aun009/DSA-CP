import pandas as pd
import numpy as np
from datetime import datetime, timedelta
import random
import os

def generate_data():
    print("Generating synthetic data...")
    
    # Constants
    NUM_USERS = 1000
    NUM_PRODUCTS = 50
    NUM_TRANSACTIONS = 10000
    
    # 1. Users
    user_ids = range(1, NUM_USERS + 1)
    users = pd.DataFrame({
        'user_id': user_ids,
        'name': [f'User {i}' for i in user_ids],
        'email': [f'user{i}@example.com' for i in user_ids],
        'signup_date': [datetime.now() - timedelta(days=random.randint(0, 365)) for _ in range(NUM_USERS)]
    })
    
    # 2. Products
    categories = ['Electronics', 'Clothing', 'Home', 'Books', 'Sports']
    products = pd.DataFrame({
        'product_id': range(1, NUM_PRODUCTS + 1),
        'name': [f'Product {i}' for i in range(1, NUM_PRODUCTS + 1)],
        'category': [random.choice(categories) for _ in range(NUM_PRODUCTS)],
        'price': [round(random.uniform(10, 500), 2) for _ in range(NUM_PRODUCTS)],
        'cost': [0 for _ in range(NUM_PRODUCTS)] # Placeholder
    })
    products['cost'] = products['price'] * 0.6 # 40% margin
    
    # 3. Transactions
    transactions = []
    start_date = datetime.now() - timedelta(days=365)
    
    for _ in range(NUM_TRANSACTIONS):
        date = start_date + timedelta(days=random.randint(0, 365))
        prod = products.sample(1).iloc[0]
        qty = random.randint(1, 5)
        
        transactions.append({
            'transaction_id': _ + 1,
            'user_id': random.choice(user_ids),
            'product_id': prod['product_id'],
            'date': date,
            'quantity': qty,
            'total_amount': prod['price'] * qty,
            'cost_amount': prod['cost'] * qty
        })
        
    transactions_df = pd.DataFrame(transactions)
    
    # Save to CSV
    os.makedirs('data', exist_ok=True)
    users.to_csv('data/users.csv', index=False)
    products.to_csv('data/products.csv', index=False)
    transactions_df.to_csv('data/transactions.csv', index=False)
    
    print("Data generation complete. Files saved to 'data/' directory.")

if __name__ == "__main__":
    generate_data()
