#include <iostream>

/*
委譲コンストラクタ
委譲コンストラクタとは複数のコンストラクタがある時
コンストラクタを他の関数にまかせること
下の例で言うとクラスStrudentのコンストラクタは２つある
１つはStudent();
２つめはStudent(std::string name, int grade, int score);
コンストラクタを委譲されている関数はvoid Student::SetData(std::string name, int grade, int score)
でこの関数をコンストラクタの初期化リストに並べることで処理が簡単になる
*/
class Student {
	std::string  mName;   // 名前
	int          mGrade;  // 学年
	int          mScore;  // 得点

public:
	Student();
	Student(std::string name, int grade, int score);

	void SetData(std::string name, int grade, int score);
	void Print();
};

Student::Student() : Student("no name", 0, 0)
{
}

Student::Student(std::string name, int grade, int score) :
mName(name), mGrade(grade), mScore(score)
{
}

void Student::SetData(std::string name, int grade, int score)
{
	mName = name;
	mGrade = grade;
	mScore = score;
}

void Student::Print()
{
	std::cout << mName.c_str() << " " << mGrade << " "
		<< mScore << std::endl;
}

int main()
{
	class Student st1;
	st1.Print();	//no name 0 0と表示
	class Student st2("takemori",3,45);
	st2.Print();	//takemori 3 45と表示

	getchar();
}