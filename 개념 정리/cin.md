## cin

- cin은 공백(띄어쓰기)을 기준으로 구분
- cin은 '\n'을 받지 않음
- case 1

```cpp
cin >> a >> b;

//a와 b를 공백(띄어쓰기)로 구분하고 엔터치면 입력 마침
//입력버퍼 앞에서부터 공백 기준으로 두개를 빼서 a, b에 넣음
```

<br>

- case 2

```cpp
do{
​	cin >> n; 
//공백을 포함한 여러 숫자를 받았다고 하면 전부 입력버퍼에 들어감
//입력버퍼 앞에서부터 공백기준으로 하나를 빼서 n에 넣음

​	cout << n << endl; 
//n을 출력(endl은 출력의끝 의미 + '\n')

}while(gect(stdin) == ' ') 
   //입력버퍼 앞에서 하나 가져온 후 공백이면 do문 다시 실행
```



+) 2623.cpp참고



## cout

- endl

  - '\n' + 출력함수의 끝을 알려서 *버퍼를 정리*

  - vscode에서는 잘 돌아가는데 백준에서는 시간초과가 뜰 때가 있음

    - 반복문에서 endl사용은 자제하자

    - ```cpp
      #include <iostream>
      using namespace std;
      int main()
      {
          int n;
          cin >> n;
          for(int i=1; i<=n; i++){
              cout << i << endl;
          }
      }
      ```

      이 경우에 endl때문에 시간초과가 발생

    - 반복문에서는 printf문을 이용하거나, cout를 이용하되 '\n'으로 줄바꿈을 하자



https://jhnyang.tistory.com/107 : cin과 getline의 차이

https://leeusin.tistory.com/418 : getline예시



- cin 과 getline의 차이
  - cin은 입력값의 기준이 공백문자, 엔터, 탭
    - getline은 입력값의 기준이 엔터
  - cin은 버퍼에서 문자를 읽다가 공백문자, 엔터, 탭을 만나면 그 전까지를 하나의 입력으로 받아들임, 공백문자/엔터/탭은 무시하지만 대신 버퍼에는 남겨둠!!!!
    - getline은 버퍼에서 문자를 읽다가 엔터를 만나면 엔터 전까지만 하나의 입력으로 받아들임, 엔터는 버퍼에 남기지 않고 버림!!!!