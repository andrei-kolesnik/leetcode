/*
608. Tree Node
https://leetcode.com/problems/tree-node/

Example 1:
Input:
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
| 2  | 1    |
| 3  | 1    |
| 4  | 2    |
| 5  | 2    |
+----+------+
Output:
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
| 2  | Inner |
| 3  | Leaf  |
| 4  | Leaf  |
| 5  | Leaf  |
+----+-------+

Example 2:
Input:
Tree table:
+----+------+
| id | p_id |
+----+------+
| 1  | null |
+----+------+
Output:
+----+-------+
| id | type  |
+----+-------+
| 1  | Root  |
+----+-------+

CREATE TABLE IF NOT EXISTS Tree (id INT, p_id INT);
TRUNCATE TABLE Tree;
INSERT INTO Tree (id, p_id) VALUES ('1', NULL);
INSERT INTO Tree (id, p_id) VALUES ('2', '1');
INSERT INTO Tree (id, p_id) VALUES ('3', '1');
INSERT INTO Tree (id, p_id) VALUES ('4', '2');
INSERT INTO Tree (id, p_id) VALUES ('5', '2');
*/

# with EXISTS
SELECT
    id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN EXISTS (SELECT * FROM Tree T2 WHERE T1.id = T2.p_id) THEN 'Inner'
        ELSE 'Leaf'
    END AS "type"
FROM Tree T1;

# with IN
SELECT
    id,
    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT p_id FROM Tree) THEN 'Inner'
        ELSE 'Leaf'
    END AS "type"
FROM Tree;
