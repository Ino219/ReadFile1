#include "draw.h"

#define PI (3.14159265358979323846264338327950288)


draw::draw(System::Drawing::Graphics^ gr) {
	graphics = gr;
	//�y���̐ݒ�
	pen = gcnew System::Drawing::Pen(System::Drawing::Color::Blue, 2);
	
	
}

System::Void draw::drawLine(System::Drawing::Point^ start, double distance,int Direction) {
	System::Drawing::Point^ end;
	double endY;
	double endX;
	switch (Direction) {
	case 0://��
		endY = start->Y + distance;
		end = gcnew System::Drawing::Point(start->X, endY);
		break;
	case 1://�E
		endX = start->X + distance;
		end = gcnew System::Drawing::Point(endX, start->Y);
		break;
	case 2://��
		endY = start->Y - distance;
		end = gcnew System::Drawing::Point(start->X, endY);
		break;
	case 3://��
		endX = start->X - distance;
		end = gcnew System::Drawing::Point(endX, start->Y);
		break;
	default:
		return;
	}

	graphics->DrawLine(pen, (System::Drawing::Point)start, (System::Drawing::Point)end);
}

System::Void draw::drawRectangle(System::Drawing::Point ^ start, double width, double height)
{
	graphics->DrawRectangle(pen, start->X, start->Y, width, height);
}

System::Void draw::drawCircle(System::Drawing::Point^ center, double radius)
{
	//���~
	System::Drawing::Point^ start = gcnew System::Drawing::Point(center->X - radius, center->Y - radius);
	graphics->DrawEllipse(pen, start->X, start->Y, radius * 2, radius * 2);
}

System::Void draw::drawDiagonalLine(System::Drawing::Pen^ pn,System::Drawing::Point^ start, double distance,int degree)
{
	System::Drawing::Point^ endPoint;
	
	//�p�x��90�x�ȉ��ɕϊ�
	double t_degree = degree % 90;
	//start�͌��_,distance�͔��a,radian�͍����ōő�360�x�̊p�x
	double radian;
	//�p�x��0����360�Ŏw��
	if (0 < degree&& degree< 90) {
		//�͈͂ɂ���āA�p�x�ɕ␳��������
		double t_degree_ = 90 - t_degree;
		//�p�x�����W�A���ɕϊ�
		radian = t_degree_ * (PI / 180);
		float x = (start->X-distance * System::Math::Cos(radian));
		float y= (start->Y-distance * System::Math::Sin(radian));
		endPoint = gcnew System::Drawing::Point(x,y);
	}
	else if (90 < degree&&degree < 180) {
		radian = t_degree * (PI / 180);
		int x = (start->X - distance * System::Math::Cos(radian));
		int y = (start->Y + distance * System::Math::Sin(radian));
		endPoint = gcnew System::Drawing::Point(x, y);
	}
	else if (180 < degree&&degree < 270) {
		double t_degree_ = 90 - t_degree;
		radian = t_degree_ * (PI / 180);
		int x = (start->X + distance * System::Math::Cos(radian));
		int y = (start->Y + distance * System::Math::Sin(radian));
		endPoint = gcnew System::Drawing::Point(x, y);
		}
	else if (270 < degree&&degree < 360) {
		radian = t_degree * (PI / 180);
		int x = (start->X + distance * System::Math::Cos(radian));
		int y = (start->Y - distance * System::Math::Sin(radian));
		endPoint = gcnew System::Drawing::Point(x, y);
	}
	else if (degree == 90) {
		drawLine(start, distance, 3);
		return;
	}
	else if (degree == 180) {
		drawLine(start, distance, 2);
		return;
	}
	else if (degree == 270) {
		drawLine(start, distance, 1);
		return;
	}
	else if (degree == 360) {
		drawLine(start, distance, 0);
	}

	graphics->DrawLine(pn, (System::Drawing::Point)start, (System::Drawing::Point)endPoint);
	//System::Windows::Forms::MessageBox::Show(endPoint->X.ToString());
}
