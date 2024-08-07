SELECT T.ID, CASE
WHEN T.RANK <= 0.25
THEN 'CRITICAL'
WHEN T.RANK <= 0.50
THEN 'HIGH'
WHEN T.RANK <= 0.75
THEN 'MEDIUM'
ELSE 'LOW'
END 'COLONY_NAME'
FROM
(SELECT ID, SIZE_OF_COLONY, PERCENT_RANK() OVER( ORDER BY SIZE_OF_COLONY DESC) as `RANK`
FROM ECOLI_DATA) as T
ORDER BY ID
;