## ios::sync_with_stdio(false); cin.tie(NULL);

- C++) cin, cout : 느림  /   C) scanf, print : 빠름

- ```cpp
  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  ```

  - C 표준 stream과 C++ 표준 stream의 동기화를 끊음

    - C 표준 stream과 C++ 표준 stream이 각각 독립적인 버퍼를 갖게됨

    - 실행 속도가 향상됨 -> cin, cout도 속도가 빨라짐

    - C와 C++의 입출력방식을 혼용해서 쓰는게 위험해짐
      - 입출력 순서를 보장할 수 없음

  - => 입출력의 속도를 향상시켜줌

    - 입출력이 엄청 많은 경우 유용
    - 애매한 시간차로 시간초과날 때 사용

cf) 기본적으로 모든 표준 stream들은 동기화 되어있음



