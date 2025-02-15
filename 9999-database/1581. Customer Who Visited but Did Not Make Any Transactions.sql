# Write your MySQL query statement below
SELECT Visits.customer_id, COUNT(customer_id) AS count_no_trans
FROM Visits
WHERE NOT EXISTS (
    SELECT 1
    FROM Transactions
    WHERE Visits.visit_id = Transactions.visit_id
)
GROUP BY Visits.customer_id;