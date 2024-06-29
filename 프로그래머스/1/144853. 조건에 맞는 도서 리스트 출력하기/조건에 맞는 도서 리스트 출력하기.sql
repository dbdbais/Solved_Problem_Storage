-- 코드를 입력하세요
SELECT book_id, Date_format(published_date,"%Y-%m-%d") from BOOK where category LIKE '인문' 
and 
YEAR(published_date) = 2021 order by published_date ;