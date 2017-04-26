/*
 * Inverse_Kinematics.c
 *
 *  Created on: Apr 17, 2017
 *      Author: Mohamed Tarek
 */
#include "Datatypes.h"
#include "math.h"
#include "LCD.h"

#define D1	73.8
#define A2	230
#define A3	3
#define D4	108.5
#define O	1
#define Pi	3.1415

f64 Angle_2,Angle_3,D;
f64 D,D_num,D_den, Gamma3 , Beta3,H3,s,rp,p;

f64 tan_inv(f64 K, f64 L)
{
	f32 R ;
	u8 f;
	f64	Result;
	if(K <0)
	{
		K = -1*K;
		R = K/L;
		f=-1;
	}else
	{
		R = K/L;
		f=1;
	}
	if(R == 1)
	{
		Result= Pi/4;
	}
	else
	{}
	if(R < 1)
	{
		Result = R-(R*R*R/3) + (R*R*R*R*R/5)-(R*R*R*R*R*R*R/7)+(R*R*R*R*R*R*R*R*R/9);
	}
	else{}
	if(R>1)
	{
		R = 1/R;
		Result = (Pi/2)-(R-(R*R*R/3) + (R*R*R*R*R/5)-(R*R*R*R*R*R*R/7)+(R*R*R*R*R*R*R*R*R/9));
	}
	Result = f*Result;
	return Result;
}
f32 coos(f32 x)
{
	return 1-(x*x/4)+(x*x*x*x/24)-(x*x*x*x*x*x/720);
}
f32 siin(f32 x)
{
	return x - (x*x*x/6) + (x*x*x*x*x/120) - (x*x*x*x*x*x*x/5040);
}
u8 Inverse_Kinematics(f32 x, f32 z)
{
	s=z-D1;
	rp = sqrt(x*x+s*s);


	if((rp>= 121.5) && (rp <= 338.5))
	{
		D_num = x*x + s*s - 64681.25;
		D_den = 2*A2*sqrt(A3*A3+D4*D4);
		D = D_num / D_den;
		p = sqrt(1-(D*D))/D;
		Gamma3 = tan_inv(p,D);
		Beta3 = tan_inv(D4,A3);
		Angle_3 =(Beta3 + Gamma3 )*(180/Pi);
		H3 = 108.45;
		Angle_2 =(tan_inv(s,x) - tan_inv(H3*siin(Gamma3),A2+(H3*coos(Gamma3))))*180/Pi;

		return 1;
	}
	else
	{
		return 0;
	}
}

f64 Theta_2(void)
{
	return 180-Angle_2;

}

f64 Theta_3(void)
{
	return 180-(Angle_3-30);
}
