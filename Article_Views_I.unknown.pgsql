// Problem: Article Views I
// URL: https://leetcode.com/problems/article-views-i/?envType=study-plan-v2&envId=top-sql-50

-- Write your PostgreSQL query statement below

SELECT DISTINCT(author_id) AS id FROM Views
WHERE viewer_id=author_id;