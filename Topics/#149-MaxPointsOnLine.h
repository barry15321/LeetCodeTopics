#pragma once

#include<cmath>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

class MaxPoints
{
public :
	int maxPoints_diu(vector<vector<int>>& points) {
		int n = points.size();
		int max_count = 0, count, duplicate;
		long long x0, y0, x1, y1, x2, y2;
		for (int i = 0; i < n; i++) 
		{
			x0 = points[i][0];
			y0 = points[i][1];
			count = 1;
			duplicate = 0;
			for (int j = i + 1; j < n; j++) 
			{
				x1 = points[j][0];
				y1 = points[j][1];
				if (x0 == x1 && y0 == y1) 
				{
					duplicate++;
					continue;
				}

				count = 2;
				for (int k = j + 1; k < n; k++) 
				{
					x2 = points[k][0];
					y2 = points[k][1];
					if (x0*y1 + x1*y2 + x2*y0 - y0*x1 - y1*x2 - y2*x0 == 0) // ¦æ¦C¦¡
						count++;					
				}

				if (max_count < count + duplicate) 
					max_count = count + duplicate;
			}

			if (max_count < duplicate + 1) 
				max_count = duplicate + 1;
		}
		return max_count;
	}

	int maxPoints(vector<vector<int>>& points)
	{
		if (points.size() < 3)
			return points.size();
		sort(points.begin(), points.end());

		int MaxValue = 0;
		int repeats = 0;
		int AbsMax = 0;
		int HorizonMax = 0;
		int VerticalMax = 0;
		
		vector<int> AxisX, AxisY;
		for (int i = 0; i < points.size(); i++)
		{
			//AbsMax = (abs(points[i][0]) > AbsMax) ? abs(points[i][0]) : AbsMax;
			//AbsMax = (abs(points[i][1]) > AbsMax) ? abs(points[i][1]) : AbsMax;
			AxisX.push_back(points[i][0]);
			AxisY.push_back(points[i][1]);

			map<pair<int, int>, int> slope;
			repeats = 1;			
			//repeats = 0;
			for (int j = i + 1; j < points.size(); j++)
			{
				if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
				{
					repeats++;
					continue;
				}
								
				int dx = points[j][0] - points[i][0];
				int dy = points[j][1] - points[i][1];
				
				int gcd_val = GCD(dx, dy);
				dx = dx / gcd_val;
				dy = dy / gcd_val;

				pair<int, int> p = { dx , dy };
				//if (slope.find(p) == slope.end()) , slope.Add
				slope[p]++;

				MaxValue = max(MaxValue, repeats);
				for (auto it = slope.begin(); it != slope.end(); it++)
					MaxValue = max(MaxValue, it->second + repeats);
					//MaxValue = max(MaxValue , it->second + repeats) + 1;
			}		
		}

		for (int i = 0; i < AxisX.size(); i++)
		{
			int vx = 0;
			int vy = 0;

			for (int j = 0; j < points.size(); j++)
			{
				if (points[j][0] == AxisX[i])
					vx++;
				if (points[j][1] == AxisY[i])
					vy++;
			}
			HorizonMax = (vx > HorizonMax) ? vx : HorizonMax;
			VerticalMax = (vy > VerticalMax) ? vy : VerticalMax;
		}
		
		MaxValue = (HorizonMax > MaxValue) ? HorizonMax : MaxValue;
		MaxValue = (VerticalMax > MaxValue) ? VerticalMax : MaxValue;

		return MaxValue;
	}

private:

	int GCD(int a, int b)
	{
		return (b == 0) ? a : GCD(b, a%b);
	}

};


