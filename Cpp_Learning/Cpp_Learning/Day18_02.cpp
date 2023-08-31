#include <iostream>
#include <vector> //c++ 라이브러리
//#include <time.h> C스타일 라이브러리

using namespace std;

int main()
{
	vector<int> vec;

	vec.push_back(3); //3을 뒤에 추가
	vec.emplace_back(4); //4을 뒤에 추가

	//insert : 임의 위치에 삽입, 매개변수가 iter
	vec.insert(vec.begin(), 10);
	//vec.insert(vec.begin() + 2, 10);

	//erase : 임의 위치 삭제, 매개변수가 iter
	vec.erase(vec.begin());

	//begin : 반환값이 처음 iter
	cout << *(vec.begin() + 1) << endl;

	//end : 반환값이 끝 + 1 iter
	//cout << *vec.end() << endl;


	//front : 처음 원소 값 참조리턴
	vec.front() = 5;
	cout << vec.front() << endl;

	//back : 마지막 원소 값 참조리턴
	vec.back() = 10;
	cout << vec.back() << endl;

	//size -> 배열의 크기

	//resize -> 배열을 잡기, 초기화
	vec.resize(10, 2); //10개의 배열을 2로 초기화
	vec.resize(10); //10개의 배열을 0로 초기화

	//reserve : 예약크기

	//capacity //배열의 내부 크기, 내부 버퍼(무언갈 저장하는 공간)

	//clear : 배열 크기 비우기
	vec.clear();
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	//shrink_to_fit : 배열 내부버퍼 비우기
	vec.shrink_to_fit();
	cout << vec.size() << endl;
	cout << vec.capacity() << endl;

	return 0;
}