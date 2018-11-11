#include<stdio.h>
#include<string.h>
#include<conio.h>


#define size 20

struct record{
	int record_id;
	char person_name[40];
	char mobile_number[11];
	int room_number;
	float duration_of_stay;
	float total_rent;
	float paid;
	float due;
};

int index = 0;  //to point rach cell of the array
int length = 0;   //to keep track of the length of the array

/*
Necessary Function for basic operation like add,edit,delete,search etc.

void add_a_new_record();  for adding a new entry
void search_by_id();  for searching the hotel_management array by record_id
void delete_a_record();   for deleting a record
void display_a_record(); to display details of a record
void display_all_record(); to diplay ditails of all records;
void hanlder(); will handle the whole operatons

*/


int search_by_id(struct record *temp,int *id){   //will search the array by the id looking for match
	if (length == 0) return -1;                  //if match, it will return the index, if not then -1;
	else{
            int i=0;
		for (;i < index; i++){
			if (temp[i].record_id == *id)return i;
			else continue;
		}
		return -1;
	}
}

struct record add_a_new_record(struct record *temp){
	if (length == size)printf("\nRecord reached maximum number!\ndelete a record first!");
	else{
		struct record temporary;   //a temporay record to hold the new record and returning it to the
		int id = 0;                //main hotel_mgmt array.
		char name[40];
		float amount = 0;
		printf("\nEnter record id (must be unique) :");
		while (1){
			scanf("%d", &id);
			if (search_by_id(temp,&id) > -1){
				printf("Already a record exist by this id, enter a new one:");
				continue;
			}
			else break;
		}
		temporary.record_id = id;

		printf("\nEnter name of the person (40 character max):");
		getchar();
		gets(name);
		strcpy(temporary.person_name, name);

		printf("\nEnter contact number :");
		strcpy(name, "");
		getchar();
		gets(name);
		strcpy(temporary.mobile_number, name);

		printf("Enter room number :");
		scanf("%d", &id);
		temporary.room_number = id;

		printf("\nEnter duration of stay :");
		scanf("%f", &amount);
		temporary.duration_of_stay = amount;

		temporary.total_rent = (temporary.duration_of_stay * 1250);
		printf("\nThe rent is cost %f BDT", temporary.total_rent);

		printf("\nEnter amount paid :");
		scanf("%f", &amount);
		temporary.paid = amount;

		temporary.due = temporary.total_rent - temporary.paid;

		printf("New Record added!");

		printf("\n=====================================");
		printf("\nRecord id          :%d", temporary.record_id);
		printf("\nName of the person :");
		puts(temporary.person_name);
		printf("\nContact number     :");
		puts(temporary.mobile_number);
		printf("\nRoom number        :%d BDT", temporary.room_number);
		printf("\nTotal rent         :%f BDT", temporary.total_rent);
		printf("\nPaid               :%f BDT", temporary.paid);
		printf("\nDue                :%f BDT", temporary.due);
		printf("\n======================================");

		return temporary;
	}
}

void delete_a_existed_record(struct record *temp){
	if (length==0)printf("\nRecord is empty!");
	else{
		int id = 0;
		printf("\nEnter record id :");
		scanf("%d", &id);
		int in = search_by_id(temp,&id);
		if (in ==-1)printf("\nDidn't match!");
		else {
                int i=0;
			for (; i < index - 1; i++){
				temp[i] = temp[i + 1];
			}
			printf("\nrequested record was deleted!");
		}
	}
}

void display_a_record(struct record *temp){
	if (length==0)printf("\nRecord is empty!");
	else{
		int id = 0;
		printf("\nEnter record id :");
		scanf("%d", &id);
		int in = search_by_id(temp,&id);
		if (in == -1)printf("\nDidn't match!");
		else{
			printf("\n=====================================");
			printf("\nRecord id          :%d", temp[in].record_id);
			printf("\nName of the person :");
			puts(temp[in].person_name);
			printf("\nContact number     :");
			puts(temp[in].mobile_number);
			printf("\nRoom number        :%d", temp[in].room_number);
			printf("\nTotal rent         :%f BDT", temp[in].total_rent);
			printf("\nPaid               :%f BDT", temp[in].paid);
			printf("\nDue                :%f BDT", temp[in].due);
			printf("\n======================================");
		}
	}
}
void display_all_records(struct record *temp){
	if (length==0)printf("\nRecord is empty!");
	else{
            int in=0;
		for (; in < index; in++){
			printf("\n=====================================");
			printf("\nRecord id          :%d", temp[in].record_id);
			printf("\nName of the person :");
			puts(temp[in].person_name);
			printf("\nContact number     :");
			puts(temp[in].mobile_number);
			printf("\nRoom number        :%d", temp[in].room_number);
			printf("\nTotal rent         :%f BDT", temp[in].total_rent);
			printf("\nPaid               :%f BDT", temp[in].paid);
			printf("\nDue                :%f BDT", temp[in].due);
			printf("\n=====================================");
		}
	}
}
void handler(void){
	char ch = '\0';
	while (ch != 'e' && ch != 'E'){
		printf("\nHotel Management system");
		struct record hotel_mgmt[size];
		printf("\npress 1 to add a record");
		printf("\npress 2 to display details about a record");
		printf("\npress 3 to delete a record");
		printf("\npress 4 to display details about all records");
		int key=0;
		printf("\nEnter :");
		scanf("%d", &key);
		switch (key){
		case 1:
		{
			hotel_mgmt[index++]=add_a_new_record(hotel_mgmt);
			length++;
			break;
		}
		case 2:
		{
			display_a_record(hotel_mgmt);
			break;
		}
		case 3:
		{
			delete_a_existed_record(hotel_mgmt);
			index--;
			length--;
			break;
		}
		case 4:
		{
			display_all_records(hotel_mgmt);
			break;
		}
		default: break;
		}
		printf("\nPress 'e' to exit to c to continue :");
		_getche();
		scanf("%c", &ch);
	}
}
int main(void){
	handler();
	return 0;
}
