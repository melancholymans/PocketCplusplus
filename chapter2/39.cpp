#include <iostream>

/*
�X�R�[�v�t���񋓌^
�񋓌^�̌^���w��
*/

using namespace std;

int main()
{
	/*
	�X�R�[�v�t���񋓌^
	*/
	int blue;
	//enum TrafficLight { blue, yellow, red };	blue�ϐ��̍Ē�`�ƃG���[���ł�
	enum struct TrafficLight  { blue, yellow, red };	//��������OK
	TrafficLight color = TrafficLight::yellow;			//�����g��
	cout << int(color) << endl;							//cout << color << endl�Ƃ���� << �ɑ΂��鉉�Z�q���Ȃ��Ƃ�����
	/*
	�񋓌^�̌^���w��
	*/
	enum struct singou:unsigned long  { blue, yellow, red };	//��������OK
	cout << typeid(singou::red).name() << endl;					//���܂��\������Ȃ�
	cout << typeid(blue).name() << endl;

	getchar();
	return 1;
}
