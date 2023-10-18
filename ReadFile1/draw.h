#pragma once
ref class draw
{

private:
	//原点
	System::Drawing::Point^ origin;

	//System::Drawing::Bitmap^ bmp;
	System::Drawing::Graphics^ graphics;
	System::Drawing::Pen^ pen;
public:
	draw(System::Drawing::Graphics^ gr);
	//原点取得と原点設定
	//System::Void setOrigin(double x, double y);
	//System::Drawing::Point getOrigin();
	//描画処理
	System::Void drawLine(System::Drawing::Point^ start, double distance, int direction);//十字直線
	System::Void drawRectangle(System::Drawing::Point^ start, double width, double height);//長方形
	System::Void drawCircle(System::Drawing::Point^ center, double radius);//円
	System::Void drawDiagonalLine(System::Drawing::Pen^ pen,System::Drawing::Point^ start, double distance,int radian);//斜め線

};

