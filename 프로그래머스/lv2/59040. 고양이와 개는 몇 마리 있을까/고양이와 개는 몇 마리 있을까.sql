-- 1. 동물 중 고양이, 개 각 몇마리?
-- 2. 고양이를 개보다 먼저 조회


SELECT ANIMAL_TYPE, COUNT(ANIMAL_ID)
FROM ANIMAL_INS
GROUP BY ANIMAL_TYPE
ORDER BY ANIMAL_TYPE;
