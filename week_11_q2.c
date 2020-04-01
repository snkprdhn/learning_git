//Sonit Kumar Pradhan
//PES2UG19CS399

#include<stdio.h>

struct stud
{
    int srn,phy,maths,elec,c,mech;
    char name[20];
    int flag;
};

float total(struct stud* temp)
{
    return (temp->phy+temp->maths+temp->elec+temp->c+temp->mech);
}

void division(int avg)
{
    if(avg>84)
    {
        printf("Division: FIRST CLASS with DISTINCTION\n");
        return;
    }
    else if(avg>59)
    {
        printf("Division: FIRST CLASS\n");
        return;
    }
    else if(avg>49)
    {
        printf("Division: SECOND CLASS\n");
        return;
    }
    else
    {
        printf("Division: THIRD CLASS\n");
    }
}

void main()
{
    int n;
    printf("enter number of students\n");
    scanf("%d",&n);
    struct stud arr[n];

    for(int i=0;i<n;i++)
    {
        printf("\nenter student SRN: ");
        scanf("%d",&arr[i].srn);
        fflush(stdin);

        printf("\nenter student name: ");
        gets(arr[i].name);

        printf("\nenter marks in physics: ");
        scanf("%d",&arr[i].phy);

        printf("\nenter marks in maths: ");
        scanf("%d",&arr[i].maths);

        printf("\nenter marks in electronics: ");
        scanf("%d",&arr[i].elec);

        printf("\nenter marks in problem solving with c: ");
        scanf("%d",&arr[i].c);

        printf("\nenter marks in mech: ");
        scanf("%d",&arr[i].mech);

        printf("\n\n");
    }


    for(int i=0;i<n;i++)
    {
        arr[i].flag=0;
        printf("Student Details\n");
        printf("---------------\n");
        printf("Student number: %d\n",arr[i].srn);
        printf("Student name: %s\n",arr[i].name);
        printf("Marks in physics: %d\n",arr[i].phy);
        arr[i].phy>39?:(arr[i].flag=1);
        printf("Marks in maths: %d\n",arr[i].maths);
        arr[i].maths>=40?:(arr[i].flag=1);
        printf("Marks in electronic: %d\n",arr[i].elec);
        arr[i].elec>=40?:(arr[i].flag=1);
        printf("Marks in problem solving with C: %d\n",arr[i].c);
        arr[i].c>=40?:(arr[i].flag=1);
        printf("Marks in mech: %d\n",arr[i].mech);
        arr[i].mech>=40?:(arr[i].flag=1);
        printf("Total marks: %d\n",(int)total(&arr[i]));
        printf("Average marks: %.2f\n",total(&arr[i])/5);

        if(arr[i].flag==1)
        {
            printf("Result: FAIL\n");
            printf("Division: F GRADE\n");
        }
        else
        {
            printf("Result: PASS\n");
            division(total(&arr[i])/5);
        }

        printf("\n\n");
    }
}
