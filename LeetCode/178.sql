-- https://leetcode.com/problems/rank-scores/

# Write your MySQL query statement below
SELECT t1.score, (SELECT COUNT(DISTINCT t2.score) FROM Scores AS t2 WHERE t2.score>=t1.score) AS "rank" FROM Scores AS t1 ORDER BY score DESC;