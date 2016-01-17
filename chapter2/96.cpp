#include <iostream>

/*
�Ϗ��R���X�g���N�^
�Ϗ��R���X�g���N�^�Ƃ͕����̃R���X�g���N�^�����鎞
�R���X�g���N�^�𑼂̊֐��ɂ܂����邱��
���̗�Ō����ƃN���XStrudent�̃R���X�g���N�^�͂Q����
�P��Student();
�Q�߂�Student(std::string name, int grade, int score);
�R���X�g���N�^���Ϗ�����Ă���֐���void Student::SetData(std::string name, int grade, int score)
�ł��̊֐����R���X�g���N�^�̏��������X�g�ɕ��ׂ邱�Ƃŏ������ȒP�ɂȂ�
*/
class Student {
	std::string  mName;   // ���O
	int          mGrade;  // �w�N
	int          mScore;  // ���_

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
	st1.Print();	//no name 0 0�ƕ\��
	class Student st2("takemori",3,45);
	st2.Print();	//takemori 3 45�ƕ\��

	getchar();
}