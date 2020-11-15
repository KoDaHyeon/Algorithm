/*
#include "Perceptron.h"

Perceptron::Perceptron(int n, std::string GATE)
{
  dimension = n;

  //weight를 랜덤으로 초기화
  //w0, w1, w2 ->  w0은 고정된 x0(=-1)과 연결, w1은 x1과 연결, w2는 x2와 연결
  weight.resize(n + 1);
  ex_weight.resize(n + 1);
  for (int i = 0; i <= n; i++){
    weight[i] = dist2(rng);
  }

  //target 계산
  if (GATE == "AND"){
    target.resize(pow(2, n), 1);
    for (int i = 0; i < pow(2, n); i++){
      for (int j = 0; j < n; j++){
        if (input[i][j] == 0){ //하나라도 0이면 target은 0
          target[i] = 0;
          break;
        }
      }
    }
  }

  else if (GATE == "OR"){
    target.resize(pow(2, n), 0);
    for (int i = 0; i < pow(2, n); i++){
      for (int j = 0; j < n; j++){
        if (input[i][j] == 1){ //하나라도 1이면 target은 1
          target[i] = 1;
          break;
        }
      }
    }
  }

  else if (GATE == "XOR"){
    target.resize(pow(2, n), 0);
    for (int i = 0; i < pow(2, n); i++){
      int cntOf1 = 0; //1의 개수
      for (int j = 0; j < n; j++){
        if (input[i][j] == 1) cntOf1++;
      }
      if (cntOf1 % 2 != 0) target[i] = 1; //1의 개수가 홀수개면 target은 1
    }
  }
}

int Perceptron::calculate(int test_case) //test_case번째 test case의 output을 계산
{
  double net = -1 * weight[0];
  for (int j = 0; j < dimension; j++){
    net += weight[j + 1] * input[test_case][j];
  }
  return (net > 0) ? 1 : 0; //해당 test case에 대한 output을 리턴
}



void Perceptron::learning(int output, int test_case) //test_case번째 test case data를 가지고 weight값을 training
{
  for (int i = 0; i <= dimension; i++){
    if (i == 0){ //w0 수정
      weight[i] += C * (target[test_case] - output) * 1 * -1;
    }
    else{ //w1. w2, .. 수정
      weight[i] += C * (target[test_case] - output) * 1 * input[test_case][i - 1];
    }
  }
}



void Perceptron::repeat_learning()
{
  int round = 1;
  bool learningable = true;
  while (learningable){
    std::cout << "[Round" << round << "]\n";

    //현재 Round의 weight 출력 및 저장
    for (int i = 0; i <= dimension; i++){
      std::cout << "weight" << i << " : " << weight[i] << "    ";
      ex_weight[i] = weight[i];
    }
    std::cout << '\n';

    int error_cnt = 0; //output!=target인 횟수

    std::cout << "output : ";
    for (int i = 0; i < pow(2, dimension); i++){ //for each training data
      int output = calculate(i);
      std::cout << output << "   ";

      if (output != target[i])
        error_cnt++;

      //weight 수정
      learning(output, i);
    }

    //feedback
    std::cout << "error_cnt : " << error_cnt << '\n';
    if (error_cnt == 0){
      std::cout << "Learning successfully.\n";
      return;
    }
    else{
      round++;
      learningable = false;

      //수정 전 weight와 값이 모두 같으면 이 perceptron은 learning 불가
      for (int i = 0; i <= dimension; i++){
        if (ex_weight[i] != weight[i])
          learningable = true;
      }
    }
  }

  std::cout << "Learning failed.\n";
}

*/