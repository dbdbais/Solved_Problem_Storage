SELECT ID, IFNULL(CHILD_COUNT,0)as `CHILD_COUNT` FROM ECOLI_DATA ED
LEFT JOIN
(SELECT PARENT_ID, COUNT(PARENT_ID) as 'CHILD_COUNT' FROM ECOLI_DATA 
WHERE PARENT_ID is NOT NULL 
GROUP BY PARENT_ID) as T on ED.ID = T.PARENT_ID
ORDER BY ID;