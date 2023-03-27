#pragma once
#include <iostream>
using namespace std;
/*
—оздать имитационную модель "остановка маршрутных
такси". Ќеобходимо вводить следующую информацию:
среднее врем€ между по€влени€ми пассажиров на остановке
в разное врем€ суток, среднее врем€ между по€влени€ми
маршруток на остановке в разное врем€ суток,
тип остановки (конечна€ или нет). Ќеобходимо определить:
среднее врем€ пребывание человека на остановке,
достаточный интервал времени между приходами маршруток,
чтобы на остановке находилось не более N людей
одновременно.  оличество свободных мест в маршрутке
€вл€етс€ случайной величиной.
*/

struct Pass {
	int time = 0; // врем€ в секундах
	Pass* next;
};

class HomeWork
{
	Pass* passHead;
	Pass* passTail;

	int countPass;
	int time_pass;
	int time_bus;
	
public:
	double avg = 0;
	HomeWork(int tPass, int tBus) : 
		countPass{ 0 }, time_pass{ tPass }, time_bus{tBus} {
		passHead = nullptr;
		passTail = nullptr;
	}

	void AddPassenger() {
		Pass* p = new Pass;
		Pass* temp = passHead;
		p->next = nullptr;

		if (passHead == nullptr)
			passHead = passTail = p;
		else {			
			passTail->next = p;
			passTail = p;
			while (temp->next != nullptr) {
				temp->time += time_pass;
				temp = temp->next;
			}
		}

		countPass++;
	}
	void DelPassenger() {
		if (countPass != 0) {
			Pass* p = passHead;
			passHead = passHead->next;
			delete p;
			countPass--;
		}
	}

	void ArrivalBus() {
		for (int i = 0; i < time_bus; i++) {
			if (i%time_pass == 0)
				AddPassenger();
		}
		int numberOfSeats = rand() % 10;
		PrintPassenger();
		while (numberOfSeats != 0)
		{
			DelPassenger(); 
			numberOfSeats--;
			
		}
		//PrintPassenger();
		cout << endl;
		avg += AveragePass();
	}

	double AveragePass() {
		Pass* p = passHead;
		int avgTime = 0;
		while (p->next != nullptr)
		{
			avgTime += p->time;
			p = p->next;
		}
		return (double)avgTime / countPass;
	}

	bool IsInterval(double N, double M) {
		if (N < M) {
			time_bus--;
			return false;
		}
		return true;
	}
	void PrintPassenger() {
		cout << " оличество людей на остановке -> "
			<< countPass << endl;
		cout << "—реднее врем€ нахождени€ на оставновке -> "
			<< AveragePass() << endl;
		cout << "¬рем€ приезда автобуса -> "
			<< time_bus << endl;
	}
};

