#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 100
struct process 
{
  int burst_time;
  int priority;
  int waiting_time;
  int turnaround_time;
};
void sort_processes(struct process processes[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (processes[j].priority > processes[j + 1].priority) {
        struct process temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }
}
int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  struct process processes[MAX_PROCESSES];
  for (int i = 0; i < n; i++) {
    printf("Enter burst time and priority for process %d: ", i + 1);
    scanf("%d%d", &processes[i].burst_time, &processes[i].priority);
  }
  sort_processes(processes, n);
  processes[0].waiting_time = 0;
  for (int i = 1; i < n; i++) {
    processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
  }
  for (int i = 0; i < n; i++) {
    processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
  }
  int total_waiting_time = 0;
  int total_turnaround_time = 0;
  for (int i = 0; i < n; i++) {
    total_waiting_time += processes[i].waiting_time;
    total_turnaround_time += processes[i].turnaround_time;
  }
  printf("Average waiting time: %f\n", (float)total_waiting_time / n);
  printf("Average turnaround time: %f\n", (float)total_turnaround_time / n);
  return 0;
}

output:
Enter the number of processes: 3
Enter burst time and priority for process 1: 30
2
Enter burst time and priority for process 2: 5
1
Enter burst time and priority for process 3: 12
3
Average waiting time: 13.333333
Average turnaround time: 29.000000

--------------------------------
Process exited after 12.64 seconds with return value 0
Press any key to continue . . .
