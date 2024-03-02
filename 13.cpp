#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
    int empId;
    char empName[50];
    float empSalary;
};
int main() {
    FILE *file;
    struct Employee emp;
    file = fopen("employee_data.dat", "rb+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("Enter employee ID: ");
    scanf("%d", &emp.empId);
    printf("Enter employee name: ");
    scanf("%s", emp.empName);
    printf("Enter employee salary: ");
    scanf("%f", &emp.empSalary);
    fseek(file, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);
    printf("\nEmployee details:\n");
    fseek(file, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, file);
    printf("ID: %d\nName: %s\nSalary: %.2f\n", emp.empId, emp.empName, emp.empSalary);
    fclose(file);
    return 0;
}
