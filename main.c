#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp;
struct cars
{
char *brand;
int power;
double price
};
struct client
{
int number;
char *name;
long tel;
struct cars car;
};
struct client first;
first.number=100;
first.name="Ivan";
first.tel=1234567;
first.car.brand="BMW";
first.car.power=2300;
first.car.price=32.600;
if((fp=fopen("cars","wb"))==NULL)
exit(1);
if((fwrite(&first,sizeof(first),1,fp))!=1)
exit(2);
fclose(fp);
struct client first1;
if((fp=fopen("cars","rb"))==NULL)
exit(1);
if((fread(&first1,sizeof(first1),1,fp))!=1)
exit(2);
fclose(fp);
printf("%d\n",first1.number);
printf("%s\n",first1.name);
printf("%d\n",first1.tel);
printf("%s\n",first1.car.brand);
printf("%d\n",first1.car.power);
printf("%lf",first1.car.price);
return 0;
}
