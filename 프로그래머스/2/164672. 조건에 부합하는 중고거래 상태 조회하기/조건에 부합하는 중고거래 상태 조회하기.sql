-- 코드를 입력하세요
SELECT BOARD_ID, WRITER_ID, TITLE, PRICE ,
case 
when STATUS LIKE 'DONE' then '거래완료'
when STATUS LIKE 'RESERVED' then '예약중'
when STATUS LIKE 'SALE' then '판매중'
end `STATUS`
from used_goods_board
WHERE YEAR(CREATED_DATE) = 2022 
and MONTH(CREATED_DATE) = 10 
and DAY(CREATED_DATE) = 5 ORDER BY BOARD_ID DESC;