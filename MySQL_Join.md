### 조인이란?
데이터베이스에서의 조인이란 **각기 다른 테이블을 한 번에 보여줄 때** 쓰는 쿼리이다.

### INNER JOIN
- 보통 얘기하는 조인을 inner join이라 한다.
- 구매 테이블과 외래키 사용자 id를 담은 사용자 테이블 B는 외래키를 이용해 inner join을 할 수 있다.

join은 두 개 이상의 테이블을 결합하기 때문에 결합하는 테이블들이 동일한 열을 가지고 있다면, '테이블명(별칭).열이름' 형식으로 테이블명을 명시해줘야한다.

### OUTER JOIN
- left | right | full outer join 한쪽 테이블에만 내용이 있어도 결과가 검색이 된다.
- 누락 없이 검색하면서도, 대상의 테이블의 내용을 가져올 수 있다. 

```SQL
SELECT
FROM userTBL U LEFT OUTER JOIN buyTBL B ON U.userID=B.userID
WHERE B.prodID IS NULL
ORDER BY U.userID;
```  
이때 구매기록이 없는 사용자도 조회가 가능하다.

### CROSS JOIN
- 모든 경우의 수를 조회
- Catesian Product

### SELF JOIN
- 자기 자신에게 조인한다.
- 같은 테이블에 두 번 참조해야하는 경우에 사용

```SQL
SELECT 이름, 천적, 수명
FROM 곤충테이블
WHERE 이름 = (  SELECT 천적
                FROM 곤충테이블
                WHERE 곤충='메뚜기');
```
^ 서브 쿼리문 이용

```SQL
SELECT
FROM 곤충도감 A INNER JOIN 곤충도감 B ON A.천적 = B.곤충
WHERE A.곤충 = '메뚜기';
```
^ INNER JOIN 사용

SELF JOIN을 사용할 때는 반드시 별칭을 이용해서 두 개의 테이블을 분리시켜야한다.
