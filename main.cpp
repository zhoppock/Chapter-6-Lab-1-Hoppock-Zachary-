// Hoppock, Zachary
// weightStatistics.cpp
// November 21, 2020
// Input the weight loss for each month in a year and calculate the total weight for the year, the average weight loss per month, and the minimum and maximum amounts of weight loss
// Version #1
#include <iostream>
#include <iomanip>
using namespace std;

/**
   Inputs weight loss values into an array
   @param weight_array an array of weight loss numbers
   @param month_name an array with the months of a year
   @param month the month indicated for the weight_array
*/
void input_loss(double weight_array[], string month_name, const int month)
{
  double weight_loss;
  cout << "Enter weight loss for " << month_name << ": ";
  cin >> weight_loss;
  while (weight_loss < 0)
  {
    cout << "Weight loss cannot be negative.  Enter weight loss for " << month_name << ": ";
    cin >> weight_loss;
  }
  weight_array[month] = weight_loss;
  cout << endl;
}

int main()
{
  const int MONTHS = 12;
  double weight[MONTHS];
  string month_names[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

  for (int i = 0; i < MONTHS; i++)
  {
    input_loss(weight, month_names[i], i);
  }

  cout << "\n------------------------------------------------------\n\n";

  double total = 0;
  for (int i = 0; i < MONTHS; i++)
  {
    total = total + weight[i];
  }
  cout << "Total yearly weight loss: " << total << " lbs.\n";

  double average = total / MONTHS;
  cout << "\nAverage monthly weight loss: " << fixed << setprecision(2) << average << " lbs.\n";

  double max_weight = weight[0];
  for (int i = 0; i < MONTHS; i++)
  {
    if (weight[i] >= max_weight)
    {
      max_weight = weight[i];
    }
  }
  cout << "\nMaximum weight loss in a single month: " << max_weight << " lbs.\n";

  double min_weight = weight[0];
  for (int i = 0; i < MONTHS; i++)
  {
    if (weight[i] <= min_weight)
    {
      min_weight = weight[i];
    }
  }
  cout << "\nMinimum weight loss in a single month: " << min_weight << " lbs.\n";
 
  return 0;
}