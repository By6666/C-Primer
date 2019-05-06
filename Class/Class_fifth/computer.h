#ifndef _COMPUTER_
#define _COMPUTER_

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};                       //CPU�������õ���ö��
class CPU                                                    //CPU��
{
public:
	CPU(CPU_Rank crank,int cfrequency,float cvoltage)        //���캯��
		:rank(crank),frequency(cfrequency),voltage(cvoltage)
	{	cout << "������һ��CPU����" << endl;  }
	CPU() = default;                                         //Ĭ�Ϲ��캯��
	CPU(const CPU &c)
		:rank(c.rank), frequency(c.frequency), voltage(c.voltage)
	{	cout << "���ƹ�����һ��CPU����" << endl;  }

	~CPU() { cout << "������һ��CPU����" << endl; }          //������������������ʱ�Զ�������

	CPU_Rank GetRank() const { return rank; }                //�������const�����ú��������޸����еı�����Ա
	int GetFrequency() const  { return frequency; }
	float GetVoltage() const { return voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetVoltage(float v) { voltage = v; }

	void CPU_run() { cout << "CPU��ʼ���У���" << endl; }
	void CPU_stop(){ cout << "CPUֹͣ���У���" << endl; }

private:
	CPU_Rank rank;
	int frequency;
	float voltage;

};


enum  RAM_Type { DDR2 = 2, DDR3, DDR4 };
class RAM
{
public:
	RAM(RAM_Type t,int f,int s)
		:type(t),frequency(f),size(s)
	{ cout << "������һ��RAM����" << endl; }
	RAM() = default;

	~RAM() { cout << "������һ��RAM����" << endl; }

	RAM_Type GetType() const { return type; }
	int GetFrequency() const { return frequency; }
	int GetSize()      const { return size; }

	void SetType(RAM_Type t) { type = t; }
	void SetFrequency(int f) { frequency = f; }
	void SetSize(float s)    { size = s; }

	void RAM_run() { cout << "RAM��ʼ���У���" << endl; }
	void RAM_stop() { cout << "RAMֹͣ���У���" << endl; }

private:
	RAM_Type type;
	int frequency;
	int size;	
};

enum CDROM_Interface { SATA, USB };
enum CDROM_Install_type { external, built_in };
class CD_RAM
{
public:
	CD_RAM(CDROM_Interface t,int s, CDROM_Install_type i)
		:interface_type(t), cach_size(s), install_type(i)
	{ cout << "������һ��CD_ROM����" << endl;}
	CD_RAM() = default;

	~CD_RAM() { cout << "������һ��CD_ROM����" << endl; }

	CDROM_Interface GetInterface_type() const { return interface_type; }
	int GetCach_Size()                  const { return cach_size; }
	CDROM_Install_type GetInstalltype() const { return install_type; }

	void SetInterface_type(CDROM_Interface t) { interface_type = t; }
	void SetCach_Size(int s)                  { cach_size = s; }
	void SetInstalltype(CDROM_Install_type i) { install_type = i; }

	void CDROM_run() { cout << "CDROM��ʼ���У���" << endl; }
	void CDROM_stop() { cout << "CDROMֹͣ���У���" << endl; }

private:
	CDROM_Interface interface_type;
	int cach_size;
	CDROM_Install_type install_type;

};

class Computer
{
public:
	Computer(CPU &c,RAM &r,CD_RAM &cd,int s,int b)                            //���ﴫ�����ܼ���һ�θ�ֵ����
		:my_cpu(c),my_ram(r),my_cdram(cd),storage_size(s),bandwidth(b)
	{ cout << "������һ��Computer����" << endl; }

	~Computer() { cout << "������һ��Computer����" << endl; }

	void Run();
	void Stop();

private:
	CPU my_cpu;
	RAM my_ram;
	CD_RAM my_cdram;
	int storage_size;
	int bandwidth;
};


void Computer::Run()
{
	my_cpu.CPU_run();
	my_ram.RAM_run();
	my_cdram.CDROM_run();
	cout << "Computer��ʼ���У���" << endl;
}
void Computer::Stop()
{
	my_cpu.CPU_stop();
	my_ram.RAM_stop();
	my_cdram.CDROM_stop();
	cout << "Computerֹͣ���У���" << endl;
}

#endif // !_COMPUTER_

