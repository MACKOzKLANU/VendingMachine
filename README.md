# Vending Machine System

This is a simple C++ program representing a vending machine system. The system includes classes for `Payment`, `Cash` (a concrete implementation of `Payment`), `Product`, `VendingMachine`, and `User`.

## Classes

### 1. Payment

- `Payment` is an abstract class with a pure virtual function `Pay()`.

### 2. Cash

- `Cash` is a concrete class derived from `Payment`.
- It implements the `Pay()` function to display a message indicating a cash payment.

### 3. Product

- `Product` represents a product with a name, price, and amount.
- It has methods to get and set the name, price, amount, and provides functionality to retrieve product information.

### 4. VendingMachine

- `VendingMachine` represents a vending machine with a collection of products and a balance of money.
- It includes methods to add products, remove products, show available products, get the count of products, and retrieve a specific product.
- It uses the `Payment` interface to process payments.

### 5. User

- `User` represents a user with a certain amount of money.
- It includes methods to get the user's money and buy a product from the vending machine, updating the user's money and the product's amount accordingly.

## Usage

The main function demonstrates the usage of the classes:

1. It creates a vending machine and adds two products (Soda and Chips) to it.
2. Displays the available products.
3. Creates a user with an initial amount of money.
4. Displays the user's available money.
5. The user buys a product from the vending machine.
6. Displays the updated list of products in the vending machine and the remaining money of the user.

<img src="screenshots/screenshot.png">
Note: Ensure that you have a C++ compiler installed on your system.

Feel free to extend and modify the code to suit your needs!
