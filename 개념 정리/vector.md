## vector

https://hwan-shell.tistory.com/119

이 블로그가 설명 끝판왕임

<br>

- ```cpp
  #include <vector> 
  using namespace std;
  ```

  필요

<br>

- **반복문 돌려서 벡터의 원소 삭제할 때**

  - ```cpp
    for(int i=0; i<v.size(); i++){
        if(v[i] == 3){
            v.erase(v.begin()+i);
            i--;
        }
    }
    ```

    - v.size() (벡터의 크기)는 원소를 삭제할때마다 업뎃됨
    - i번째 요소를 삭제하면 원래 i+1번째였던 요소가 i번째가 되면서 원소들이 앞으로 하나씩 밀림
    - 삭제한 경우에는 삭제 후 iterator를 한칸 앞으로 옮겨줘야 다음 원소를 조회할 수 있음

  - 2056.cpp 참고

<br>

- **resize 함수**

  - ```cpp
    vector<int> list;
    list.resize(10); //벡터의 사이즈는 10, 모든 원소를 0으로 초기화
    list.resize(5, 3); //벡터의 사이즈는 5, 모든 원소를 3으로 초기화
    
    vector<int> list2= {1,2,3};
    list2.resize(5); //list2 = {1,2,3,0,0}
    ```

    - 벡터의 내부 용량을 딱 정해놓는 것
    - resize후에는 바로 **'벡터이름[index]'**로 원소에 접근 가능
    - 사이즈를 10으로 해놨을 경우, 15개의 데이터가 들어와도 5개는 버려짐, 7개의 데이터가 들어와도 사이즈는 10으로 유지

  - 벡터 선언시 벡터의 크기를 정할 수 없는 경우

      - 벡터 선언 -> resize로 벡터의 원소 개수 정해주기

        ```cpp
        vector<int> list;
        int size; //벡터 원소 개수
        cin >> size;
        list.resize(size); //벡터크기 size, 모든 원소는 0으로 초기화됨
        ```

  - 메모리를 추가로 할당받을 때, 원래 메모리의 용량을 늘리는 것이 아닌, 더 큰 메모리를 할당해서 그곳에 데이터를 복사하고, 이전 데이터는 삭제함<br>

    => 속도상 효율적이지 않음<br>

    => resize로 미리 메모리 크기를 정해두고 사용하자!

  - cf) 배열에선 불가능

<br>

- **fill 함수**

  - ```cpp
    #include <algorithm>
    
    fill(채우고자 하는 자료구조의 시작위치, 채우고자 하는 자료구조의 끝위치, 채우고자 하는 값);
    //채우고자 하는 자료구조의 끝위치 iterator는 포함하지 않음!!!
    ```

    - 배열, 벡터에서 사용 가능

    - 벡터<br>

      ```cpp
      #include <algorithm>
      
      vector<int> list(8);
      list.fill(list.begin(), list.begin()+4, 7); //인덱스0~3까지 7로 할당
      list.fill(list.begin()+4, list.end(), 3); //인덱스 4~끝까지 3으로 할당
      ```

    - 배열<br>

      ```cpp
      #include <algorithm>
      
      int a[8] = {0,};
      fill(a, a+4, 7); //인덱스 0~3까지 7로 할당
      fill(a+4, a+sizeof(a)/sizeof(int), 3); //인덱스4~끝까지 3으로 할당
      ```

<br>

- **2차원 벡터**

  - 선언과 동시에 할당

    - ```cpp
      vector < vector<int> > v(int, vector<int>(3));
      ```

      크기가 3인 벡터를 각각 원소로 갖는 2차원 벡터

    - ```cpp
      vector < vector<int> > v(5, vector<int>(3, 1));
      ```

      5개의 행, 3개의 열(값이 모두 1)인 2차원 벡터

      (크기가 3이고 값이 모두 1인 벡터 5개를 원소로 갖는 벡터)
    
    - ```cpp
    vector < vector<int> > v(5, vector<int>());
      ```

      벡터를 원소로 갖는, 크기가 5인 2차원 벡터(5개의 행)

  - 선언 후 할당

    - ```cpp
    vector< vector<int> > v;
      v.assign(5, vector<int>(3, 1)); 
      //5개의행, 3개의 열(값이 모두 1)인 2차원벡터 공간 할당
      ```

    - ```cpp
      vector< vector<int> > v; //2차원벡터 선언
      vector<int> v_ele; //2차원벡터에 각 원소로 들어갈 1차원벡터를 선언해줘야 함
      v.emplace_back(v_ele); //v[0]
    v.emplace_back(v_ele); //v[1]
      v[0].emplace_back(3); //v[0][0] == 3;
    v[0].emplace_back(4); //v[0][1] == 4;
      ```

  - 접근

    - ```cpp
      for(int i=0; i<v.size(); i++){
      	for(int j=0; j<v[i].size(); j++){
      	cout << v[i][j];
      	}
      	cout << '\';
      }
      ```

      ' v [행] [열] '형태로 접근

  - 1780.cpp 참고