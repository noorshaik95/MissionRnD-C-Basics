/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int valid(int date, int month, int year)
{
	if ((date != 0) && (month != 0) && (year != 0))
	{
		if (month >= 1 && month <= 12)
		{
			switch (month)
			{
			case 1:if (date > 31) return 0; break;
			case 2:if (date > 29)  return 0; break;
			case 3:if (date > 31) return 0; break;
			case 4:if (date > 30) return 0; break;
			case 5:if (date > 31) return 0; break;
			case 6:if (date > 30) return 0; break;
			case 7:if (date > 31) return 0; break;
			case 8:if (date > 31) return 0; break;
			case 9:if (date > 30) return 0; break;
			case 10:if (date > 31) return 0; break;
			case 11:if (date > 30) return 0; break;
			case 12:if (date > 31) return 0; break;
			default: return 0; break;
			};
			if (date == 29 && month == 2)
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
					return (1);
				else return 0;
			}
		}
		else
			return 0;

	}
	else if ((date == 0) || (month == 0) || (year == 0))
		return 0;
	return 1;
}

int isOlder(char *dob1, char *dob2)
{
	int i;
	int temp1 = 0, temp2 = 0, a, b;
	int date1, month1, year1, date2, month2, year2;
	for (i = 0; dob1[i] != '\0' && dob2[i] != '\0'; i++)
	{
		if (dob1[i] != '-')
		{
			temp1 = (temp1 * 10) + (dob1[i] - 48);
			temp2 = (temp2 * 10) + (dob2[i] - 48);
		}
		if (i == 1)
		{
			date1 = temp1;
			date2 = temp2;
			temp1 = 0;
			temp2 = 0;
		}
		else if (i == 4)
		{
			month1 = temp1;
			month2 = temp2;
			temp1 = 0;
			temp2 = 0;
		}
		else if (i == 9)
		{
			year1 = temp1;
			year2 = temp2;
		}
	}
	
	if (dob1[i] == '\0' && dob2[i] == '\0')
	{
		a = valid(date1, month1, year1);
		b = valid(date2, month2, year2);
	
		if (a == 1 && b == 1)
		{
			if (year1 < year2)
				return 1;
			else if (year2 < year1)
				return 2;
			else if (month1 < month2)
				return 1;
			else if (month2 < month1)
				return 2;
			else if (date1 < date2)
				return 1;
			else if (date2 < date1)
				return 2;
			else
				return 0;
		}

	}
	return -1;
}


