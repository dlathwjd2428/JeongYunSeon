#include<stdio.h>
#include<list>
#include<vector>
#include<map>//레드블랙트리
//이진탐색트리
//B tree, AVL tree, Red Black tree > 왼쪽과 오른쪽의 밸런스를 잡기 위한 트리

//vector(정보가 들어가는 순서가 중요할 때
//장점
//특정 원소에 접근이 빠르다.
//마지막 위치에 정보를 추가하는 동작이 빠르다.
//단점
//사이에 있는 정보의 추가 삭제 수정 등이 느리다.

//list(개별적인 정보들의 추가 삭제 수정 등이 중요할때
//장점
//사이에 있는 정보의 추가 삭제 수정 등이 빠르다.
//단점
//특정 원소에 접근이 느리다.
//마지막 위치에 정보를 추가하는 동작이 느리다.

void ShowVector(std::vector<int>iVector)
{
	//iVector.size() 원소의 개수 반환
	for (int i = 0; i < iVector.size(); i++)
		printf("iVector[%d]: %d\n", i, iVector[i]);
}
void ShowVector2(std::vector<int>iVector)
{
	for (int i = 0; i < iVector.size(); i++)
		printf("iVector.at(%d): %d\n", i, iVector.at(i));
}
void ShowVector3(std::vector<int>iVector)
{
	for (auto iter = iVector.begin(); iter != iVector.end(); iter++)
		printf("*iter: %d\n", *iter);
}
int main()
{
	std::vector<int> iVector;

	for (int i = 1; i <= 10; i++)
	{
		iVector.push_back(i);
	}
	printf("Front: %d\tBack: %d\n", iVector.front(), iVector.back());
	ShowVector(iVector);
	ShowVector2(iVector);
	ShowVector3(iVector);

	//iVector.clear() 원소 전체 삭제
	//iVector.empty() 비어있는지 확인하는 함수 비어있으면 참 반환
	//iVector.erase() 원하는 것만 삭제
	//iter 시작주소 반환

	auto iter = find(iVector.begin(), iVector.end(), 11);
	if (iter == iVector.end())
		printf("데이터가 존재하지 않습니다.\n");
	else
	{
		iVector.erase(iter);
		ShowVector3(iVector);
	}

	iter = find(iVector.begin(), iVector.end(), 6);
	if (iter == iVector.end())
		printf("데이터가 존재하지 않습니다.\n");
	else
	{
		iVector.erase(iter);
		ShowVector3(iVector);
	}

	iter = find(iVector.begin(), iVector.end(), 7);
	if (iter == iVector.end())
		printf("데이터가 존재하지 않습니다.\n");
	else
	{
		iVector.insert(iter, 11);
		ShowVector3(iVector);
	}
	iVector.pop_back();//마지막 정보 삭제

	std::list<int> iList;
	iList.pop_front(); //앞의 정보를 삭제
	iList.push_front(); //앞의 정보를 추가

}
