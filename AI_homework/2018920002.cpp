#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;
const double C = 0.1; //learning rate
random_device rng;
uniform_real_distribution<double> dist2(-2.0, 2.0);  // [-2.0, 2.0) 범위 내의 실수
vector<vector<int>> input;


class Perceptron
{
  private:
    int dimension;
    vector<double> weight;
    vector<double> ex_weight;
    vector<int> target;


  public:
    Perceptron(int n, string GATE) //생성자 : input이 n차원(x1, x2, .., xn), weight 랜덤으로 초기화, target 계산
    {
      dimension = n;

      //weight를 랜덤으로 초기화
      //w0, w1, w2 ->  w0은 고정된 x0(=-1)과 연결, w1은 x1과 연결, w2는 x2와 연결
      weight.resize(n+1);
      ex_weight.resize(n+1);
      for(int i=0; i<=n; i++){
        weight[i] = dist2(rng);
      }

      //target 계산
      if(GATE == "AND")
      {
        target.resize(pow(2,n), 1);
        for(int i=0; i<pow(2,n); i++){
          for(int j=0; j<n; j++){
            if(input[i][j] == 0){ //하나라도 0이면 target은 0
              target[i] = 0;
              break;
           }
          }
        }
      }

      else if(GATE == "OR")
      {
        target.resize(pow(2,n), 0);
        for(int i=0; i<pow(2,n); i++){
          for(int j=0; j<n; j++){
            if(input[i][j] == 1){ //하나라도 1이면 target은 1
              target[i] = 1;
              break;
           }
          }
        }
      }

      else if(GATE == "XOR")
      {
        target.resize(pow(2,n), 0);
        for(int i=0; i<pow(2,n); i++){
          int cntOf1=0; //1의 개수
          for(int j=0; j<n; j++){
            if(input[i][j] == 1){
              cntOf1++;
            }
          }
          if(cntOf1%2 != 0) target[i] = 1; //1의 개수가 홀수개면 target은 1
        }
      }


    }



    int calculate(int test_case) //test_case번째 test case의 output을 계산
    {
      //calculate output
      double net = -1 * weight[0];
      for(int j=0; j<dimension; j++){
        net += weight[j+1]*input[test_case][j];
      }
      
      return (net > 0)? 1 : 0; //해당 test case에 대한 output을 리턴
    }

   
    void learning(int output, int test_case) //test_case번째 test case data를 가지고 weight값을 training
    {

      for(int i=0; i<=dimension; i++){
        if(i==0){ //w0 수정
          weight[i] += C * (target[test_case] - output) * 1 * -1;
        }
        else{ //w1. w2, .. 수정
          weight[i] += C * (target[test_case] - output) * 1 * input[test_case][i-1];
        }
      }

    }



    void repeat_learning()
    {
      int round=1;
      bool learningable = true;
      while(learningable)
      {
        cout << "[Round" << round << "]\n";

        //현재 Round의 weight 출력 및 저장
        for(int i=0; i<=dimension; i++){
          cout << "weight" << i << " : " << weight[i] << "    ";
          ex_weight[i] = weight[i];      
        }
        cout <<'\n';
        

        int error_cnt = 0; //output!=target인 횟수

        
        cout << "output : ";
        for (int i = 0; i < pow(2, dimension); i++){ //for each training data
          int output = calculate(i);
          cout << output << "   ";

          if(output != target[i]) error_cnt++;

          //weight 수정
          learning(output, i);
        }

        //feedback
        cout << "error_cnt : " << error_cnt << '\n';
        if(error_cnt == 0){ 
          cout << "Learning successfully.\n";
          return;
        }
        else{
          round++;
          learningable = false;

          //수정 전 weight와 값이 모두 같으면 이 perceptron은 learning 불가
          for(int i=0; i<=dimension; i++){
            if(ex_weight[i] != weight[i]) learningable = true;
          }

        }

      }
       
      cout << "Learning failed.\n";
    }

};






int main()
{
  int n; //input은 n차원
  cin >> n;
  input.assign(pow(2,n), vector<int>(n, 0));


  //input 값 초기화
  //input[i][0]=x1, input[i][1]=x2, x0=-1
  for(int i=0; i<pow(2,n); i++){
    for(int now=n-1, j=0; now>=0 && j<n; now--, j++){
      if(i & (1 << now)) //i의 now번째 비트가 1이라면
        input[i][j] = 1;
      else input[i][j] = 0;
    }
  }

  cout << "AND gate learning \n";
  Perceptron AND_perceptron(n, "AND");
  AND_perceptron.repeat_learning();

  
  cout << "\n OR gate learning \n";
  Perceptron OR_perceptron(n, "OR");
  OR_perceptron.repeat_learning();

  
  cout << "\n XOR gate learning \n";
  Perceptron XOR_perceptron(n, "XOR");
  XOR_perceptron.repeat_learning();

}
