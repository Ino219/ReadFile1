#pragma once
ref class draw
{

private:
	//���_
	System::Drawing::Point^ origin;

	//System::Drawing::Bitmap^ bmp;
	System::Drawing::Graphics^ graphics;
	System::Drawing::Pen^ pen;
public:
	draw(System::Drawing::Graphics^ gr);
	//���_�擾�ƌ��_�ݒ�
	//System::Void setOrigin(double x, double y);
	//System::Drawing::Point getOrigin();
	//�`�揈��
	System::Void drawLine(System::Drawing::Point^ start, double distance, int direction);//�\������
	System::Void drawRectangle(System::Drawing::Point^ start, double width, double height);//�����`
	System::Void drawCircle(System::Drawing::Point^ center, double radius);//�~
	System::Void drawDiagonalLine(System::Drawing::Pen^ pen,System::Drawing::Point^ start, double distance,int radian);//�΂ߐ�

};

