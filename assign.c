#include <stdio.h>
int main() {
int n, i;
char pid[20][10];
int at[20], bt[20];
int wt[20], tat[20];
int ct[20];
float avg_wt = 0, avg_tat = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
printf("Enter PID ArrivalTime BurstTime:\n");
for(i = 0; i < n; i++) {
scanf("%s %d %d", pid[i], &at[i], &bt[i]);
}
ct[0] = at[0] + bt[0];
wt[0] = 0;
tat[0] = bt[0];
for(i = 1; i < n; i++) {
if(ct[i-1] < at[i])
ct[i] = at[i] + bt[i];
else
ct[i] = ct[i-1] + bt[i];
wt[i] = ct[i] - at[i] - bt[i];
tat[i] = ct[i] - at[i];
}
printf("\nWaiting Time:\n");
for(i = 0; i < n; i++) {
printf("%s %d\n", pid[i], wt[i]);
avg_wt += wt[i];
}
printf("\nTurnaround Time:\n");
for(i = 0; i < n; i++) {
printf("%s %d\n", pid[i], tat[i]);
avg_tat += tat[i];
}
avg_wt = avg_wt / n;
avg_tat = avg_tat / n;
printf("\nAverage Waiting Time: %.2f\n", avg_wt);
printf("Average Turnaround Time: %.2f\n", avg_tat);
return 0;
}
