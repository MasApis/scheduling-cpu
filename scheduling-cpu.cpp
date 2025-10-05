#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
	string nameProcess; // proses (P1, P2, dll.)
	int at; // arrival time
	int bt; // burst time
	int st; // start time
	int cn; // completion
	int wg; // waiting
	int td; // turnarround
	int pr; // priority
};

void fcfsProcess() {
	double avg_td = 0;
	double avg_wg = 0;
	int n;
	cout << "Masukkan jumlah proses : ";
	cin >> n;

	Process p[n];

	for(int i = 0; i < n; i++) {
		cout << "Masukkan nama proses (Contoh P1/P2/P3) : ";
		cin >> p[i].nameProcess;
		cout << "Maukkan arrival time : ";
		cin >> p[i].at;
		cout << "Masukkan burst time : ";
		cin >> p[i].bt;
	} 

	// Mengurutkan arrival time menggunakan algoritma insertion sort
	for(int i = 1; i < n; i++) {
		Process key = p[i];
		int j = i - 1;

		while(j >= 0 && p[j].at > key.at) {
			p[j+1] = p[j]; 
			j--;
		}	
		
		p[j+1] = key;
	}

	// Menghitung start time
	for (int i = 0; i < n; i++)
	{
		if(i == 0) {
			p[i].st = p[i].at;
		} else {
			p[i].st = max(p[i-1].cn, p[i].at);
		}

		// Menghitung completion time
		p[i].cn = p[i].st + p[i].bt;
		// Menghitung turnarround time
		p[i].td = p[i].cn - p[i].at;
		// Menghitung waiting time
		p[i].wg = p[i].td - p[i].bt;
	}
	
	// Menghitung rata-rata turnarround time dan waiting time
	for(int i = 0; i < n; i++) {
		avg_td += p[i].td;
		avg_wg += p[i].wg;
	}

	avg_td = avg_td / n;
	avg_wg = avg_wg / n;


	// Mencetak nama prcess, arrival time, burst time, start time, completion time, turnarround time, wating time.
	cout << "PROCESS\tAT\tBT\tST\tCT\tTD\tWN\n";
	for (int i = 0; i < n; i++)
	{
		cout << p[i].nameProcess << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].cn << "\t" << p[i].td << "\t" << p[i].wg << "\n";
	}

	// Mencetak rata-rata turnarround time dan waiting time
	cout << "Average turnarround time = " << avg_td << endl;
	cout << "Average waiting time = " << avg_wg << endl;
}

void sjfProcess() {
	double avg_td = 0;
	double avg_wg = 0;
	int n;
	cout << "Masukkan jumlah proses : ";
	cin >> n;

	Process p[n];

	for(int i = 0; i < n; i++) {
		cout << "Masukkan nama proses (Contoh P1/P2/P3) : ";
		cin >> p[i].nameProcess;
		cout << "Maukkan arrival time : ";
		cin >> p[i].at;
		cout << "Masukkan burst time : ";
		cin >> p[i].bt;
	} 

	// Mengurutkan burst time menggunakan algoritma insertion sort
	for(int i = 1; i < n; i++) {
		Process key = p[i];
		int j = i - 1;

		while(j >= 0 && p[j].bt > key.bt) {
			p[j+1] = p[j]; 
			j--;
		}	
		
		p[j+1] = key;
	}

	// Menghitung start time
	for (int i = 0; i < n; i++)
	{
		if(i == 0) {
			p[i].st = p[i].at;
		} else {
			p[i].st = max(p[i-1].cn, p[i].at);
		}

		// Menghitung completion time
		p[i].cn = p[i].st + p[i].bt;
		// Menghitung turnarround time
		p[i].td = p[i].cn - p[i].at;
		// Menghitung waiting time
		p[i].wg = p[i].td - p[i].bt;
	}
	
	// Menghitung rata-rata turnarround time dan waiting time
	for(int i = 0; i < n; i++) {
		avg_td += p[i].td;
		avg_wg += p[i].wg;
	}

	avg_td = avg_td / n;
	avg_wg = avg_wg / n;


	// Mencetak nama prcess, arrival time, burst time, start time, completion time, turnarround time, wating time.
	cout << "PROCESS\tAT\tBT\tST\tCT\tTD\tWN\n";
	for (int i = 0; i < n; i++)
	{
		cout << p[i].nameProcess << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].cn << "\t" << p[i].td << "\t" << p[i].wg << "\n";
	}

	// Mencetak rata-rata turnarround time dan waiting time
	cout << "Average turnarround time = " << avg_td << endl;
	cout << "Average waiting time = " << avg_wg << endl;
}

void priorityProcess() {
	double avg_td = 0;
	double avg_wg = 0;
	int n;
	cout << "Masukkan jumlah proses : ";
	cin >> n;

	Process p[n];

	for(int i = 0; i < n; i++) {
		cout << "Masukkan nama proses (Contoh P1/P2/P3) : ";
		cin >> p[i].nameProcess;
		cout << "Maukkan arrival time : ";
		cin >> p[i].at;
		cout << "Masukkan burst time : ";
		cin >> p[i].bt;
        cout << "Masukkan priority : ";
		cin >> p[i].pr;
	} 

	// Mengurutkan prority time menggunakan algoritma insertion sort
	for(int i = 1; i < n; i++) {
		Process key = p[i];
		int j = i - 1;

		while(j >= 0 && p[j].pr > key.pr) {
			p[j+1] = p[j]; 
			j--;
		}	
		
		p[j+1] = key;
	}

	// Menghitung start time
	for (int i = 0; i < n; i++)
	{
		if(i == 0) {
			p[i].st = p[i].at;
		} else {
			p[i].st = max(p[i-1].cn, p[i].at);
		}

		// Menghitung completion time
		p[i].cn = p[i].st + p[i].bt;
		// Menghitung turnarround time
		p[i].td = p[i].cn - p[i].at;
		// Menghitung waiting time
		p[i].wg = p[i].td - p[i].bt;
	}
	
	// Menghitung rata-rata turnarround time dan waiting time
	for(int i = 0; i < n; i++) {
		avg_td += p[i].td;
		avg_wg += p[i].wg;
	}

	avg_td = avg_td / n;
	avg_wg = avg_wg / n;


	// Mencetak nama prcess, arrival time, burst time, start time, completion time, turnarround time, wating time.
	cout << "PROCESS\tAT\tBT\tPR\tST\tCT\tTD\tWN\n";
	for (int i = 0; i < n; i++)
	{
		cout << p[i].nameProcess << "\t" << p[i].at << "\t" << p[i].bt << "\t"<< p[i].pr <<"\t"<< p[i].st << "\t" << p[i].cn << "\t" << p[i].td << "\t" << p[i].wg << "\n";
	}

	// Mencetak rata-rata turnarround time dan waiting time
	cout << "Average turnarround time = " << avg_td << endl;
	cout << "Average waiting time = " << avg_wg << endl;
}

void roundRobinProcess() {
    int n, tq;
    cout << "Masukkan jumlah proses : ";
    cin >> n;
    cout << "Masukkan Time Quantum : ";
    cin >> tq;

    Process p[n];

	// sisa burst time
    int rt[n]; 

    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama proses (Contoh P1/P2/P3) : ";
        cin >> p[i].nameProcess;
        cout << "Masukkan arrival time : ";
        cin >> p[i].at;
        cout << "Masukkan burst time : ";
        cin >> p[i].bt;
        rt[i] = p[i].bt;
    }

    int time = 0, done = 0;
    double avg_td = 0, avg_wg = 0;

    while (done < n) {
        bool progress = false;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && p[i].at <= time) {
                progress = true;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    p[i].cn = time;
                    p[i].td = p[i].cn - p[i].at;
                    p[i].wg = p[i].td - p[i].bt;
                    avg_td += p[i].td;
                    avg_wg += p[i].wg;
                    done++;
                }
            }
        }
		// kalau tidak ada proses yang jalan
        if (!progress) time++; 
    }

    avg_td /= n;
    avg_wg /= n;

    cout << "PROCESS\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].nameProcess << "\t" << p[i].at << "\t" << p[i].bt
             << "\t" << p[i].cn << "\t" << p[i].td << "\t" << p[i].wg << endl;
    }

    cout << "Average Turnaround Time = " << avg_td << endl;
    cout << "Average Waiting Time = " << avg_wg << endl;
}


int main() {
    int choice;
    do {
        cout << "\n===== MENU CPU SCHEDULING =====\n";
        cout << "1. FCFS\n";
        cout << "2. SJF\n";
        cout << "3. Priority (Non-Preemptive)\n";
        cout << "4. Round Robin\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\n--- FCFS ---\n";
                fcfsProcess();
                break;
            case 2:
                cout << "\n--- SJF ---\n";
                sjfProcess();
                break;
            case 3:
                cout << "\n--- Priority ---\n";
                priorityProcess();
                break;
            case 4:
                cout << "\n--- Round Robin ---\n";
                roundRobinProcess();
                break;
            case 0:
                cout << "Terima kasih, program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 0);

    return 0;
}