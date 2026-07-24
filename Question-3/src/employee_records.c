#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main(void)
{
    int fd;

    /* Create/open the employee file */
    fd = open(
        "files/employees.dat",
        O_CREAT | O_RDWR | O_TRUNC,
        0644
    );

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File created successfully.\n");

    /* Initial employee records */
    struct Employee employees[] = {
        {101, "Arun", 35000},
        {102, "Priya", 42000},
        {103, "Rahul", 38000}
    };

    /* Write all initial records */
    ssize_t bytes_written = write(
        fd,
        employees,
        sizeof(employees)
    );

    if (bytes_written == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Employee records written successfully.\n");
    printf("Bytes written: %ld\n", (long)bytes_written);

    /* Updated data for employee 102 */
    struct Employee updated = {
        102,
        "Priya",
        50000
    };

    /* Move directly to the second employee record */
    if (lseek(
            fd,
            1 * sizeof(struct Employee),
            SEEK_SET
        ) == -1)
    {
        perror("lseek update");
        close(fd);
        return 1;
    }

    /* Overwrite only employee 102 */
    if (write(fd, &updated, sizeof(updated)) == -1)
    {
        perror("write update");
        close(fd);
        return 1;
    }

    printf("Employee 102 updated using lseek().\n");

    /* Variable for retrieving one employee */
    struct Employee retrieved;

    /* Jump directly back to employee 102 */
    if (lseek(
            fd,
            1 * sizeof(struct Employee),
            SEEK_SET
        ) == -1)
    {
        perror("lseek read");
        close(fd);
        return 1;
    }

    /* Read only that employee record */
    if (read(fd, &retrieved, sizeof(retrieved)) == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    printf("\nRetrieved employee record:\n");
    printf("ID: %d\n", retrieved.id);
    printf("Name: %s\n", retrieved.name);
    printf("Salary: %.2f\n", retrieved.salary);

    /* Close the file descriptor */
    if (close(fd) == -1)
    {
        perror("close");
        return 1;
    }

    printf("\nFile closed successfully.\n");

    return 0;
}
