
CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    quantity INTEGER NOT NULL DEFAULT 0
);
CREATE TABLE operations_log (
    id SERIAL PRIMARY KEY,
    product_id INTEGER REFERENCES products(id),
    operation VARCHAR(10) CHECK (operation IN ('ADD', 'REMOVE')),
    quantity INTEGER NOT NULL,
    operation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
CREATE OR REPLACE FUNCTION update_stock(product_id INT, operation VARCHAR, quantity INT) 
RETURNS VOID AS $$
BEGIN
    IF operation = 'ADD' THEN
        UPDATE products
        SET quantity = quantity + quantity
        WHERE id = product_id;

    ELSIF operation = 'REMOVE' THEN
        UPDATE products
        SET quantity = quantity - quantity
        WHERE id = product_id AND quantity >= quantity;
        IF NOT FOUND THEN
            RAISE EXCEPTION 'Недостаточно товара на складе для операции REMOVE';
        END IF;
    ELSE
        RAISE EXCEPTION 'Некорректная операция: %', operation;
    END IF;

    INSERT INTO operations_log (product_id, operation, quantity)
    VALUES (product_id, operation, quantity);
END;
$$ LANGUAGE plpgsql;
CREATE TRIGGER stock_operations_trigger
AFTER INSERT OR UPDATE ON products
FOR EACH ROW
EXECUTE FUNCTION update_stock(NEW.id, NEW.operation, NEW.quantity);
