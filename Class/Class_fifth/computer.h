#ifndef _COMPUTER_
#define _COMPUTER_

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

enum CPU_Rank{P1=1,P2,P3,P4,P5,P6,P7};                       //CPU类中所用到的枚举
class CPU                                                    //CPU类
{
public:
	CPU(CPU_Rank crank,int cfrequency,float cvoltage)        //构造函数
		:rank(crank),frequency(cfrequency),voltage(cvoltage)
	{	cout << "构造了一个CPU！！" << endl;  }
	CPU() = default;                                         //默认构造函数
	CPU(const CPU &c)
		:rank(c.rank), frequency(c.frequency), voltage(c.voltage)
	{	cout << "复制构造了一个CPU！！" << endl;  }

	~CPU() { cout << "析构了一个CPU！！" << endl; }          //析构函数，对象消亡时自动被调用

	CPU_Rank GetRank() const { return rank; }                //函数后加const声明该函数不能修改类中的变量成员
	int GetFrequency() const  { return frequency; }
	float GetVoltage() const { return voltage; }

	void SetRank(CPU_Rank r) { rank = r; }
	void SetFrequency(int f) { frequency = f; }
	void SetVoltage(float v) { voltage = v; }

	void CPU_run() { cout << "CPU开始运行！！" << endl; }
	void CPU_stop(){ cout << "CPU停止运行！！" << endl; }

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
	{ cout << "构造了一个RAM！！" << endl; }
	RAM() = default;

	~RAM() { cout << "析构了一个RAM！！" << endl; }

	RAM_Type GetType() const { return type; }
	int GetFrequency() const { return frequency; }
	int GetSize()      const { return size; }

	void SetType(RAM_Type t) { type = t; }
	void SetFrequency(int f) { frequency = f; }
	void SetSize(float s)    { size = s; }

	void RAM_run() { cout << "RAM开始运行！！" << endl; }
	void RAM_stop() { cout << "RAM停止运行！！" << endl; }

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
	{ cout << "构造了一个CD_ROM！！" << endl;}
	CD_RAM() = default;

	~CD_RAM() { cout << "析构了一个CD_ROM！！" << endl; }

	CDROM_Interface GetInterface_type() const { return interface_type; }
	int GetCach_Size()                  const { return cach_size; }
	CDROM_Install_type GetInstalltype() const { return install_type; }

	void SetInterface_type(CDROM_Interface t) { interface_type = t; }
	void SetCach_Size(int s)                  { cach_size = s; }
	void SetInstalltype(CDROM_Install_type i) { install_type = i; }

	void CDROM_run() { cout << "CDROM开始运行！！" << endl; }
	void CDROM_stop() { cout << "CDROM停止运行！！" << endl; }

private:
	CDROM_Interface interface_type;
	int cach_size;
	CDROM_Install_type install_type;

};

class Computer
{
public:
	Computer(CPU &c,RAM &r,CD_RAM &cd,int s,int b)                            //这里传引用能减少一次赋值构造
		:my_cpu(c),my_ram(r),my_cdram(cd),storage_size(s),bandwidth(b)
	{ cout << "构造了一个Computer！！" << endl; }

	~Computer() { cout << "析构了一个Computer！！" << endl; }

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
	cout << "Computer开始运行！！" << endl;
}
void Computer::Stop()
{
	my_cpu.CPU_stop();
	my_ram.RAM_stop();
	my_cdram.CDROM_stop();
	cout << "Computer停止运行！！" << endl;
}

#endif // !_COMPUTER_

