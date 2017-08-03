//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x= -8;
int y= -8;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBTimer(TObject *Sender)
{
         b->Left +=x;
         b->Top +=y;



      //   kolizje z scianami
      if (b->Top-5 <=tlo->Top) y=-y;
      if (b->Top+5+b->Height>=tlo->Height) y=-y;

      
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerP1GTimer(TObject *Sender)
{
                p1->Top-=8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerP1DTimer(TObject *Sender)
{
                p1->Top+=8 ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerP2GTimer(TObject *Sender)
{
                p2->Top-=8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerP2DTimer(TObject *Sender)
{
                 p2->Top+=8 ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
          if(Key==0x41) TimerP1G->Enabled=true;          //klawisz A
          if(Key==0x5A) TimerP1D->Enabled=true;              // klawisz Z
          if(Key==VK_UP) TimerP2G->Enabled=true;
          if(Key==VK_DOWN) TimerP2D->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
          if(Key==0x41) TimerP1G->Enabled=false;          //klawisz A
          if(Key==0x5A) TimerP1D->Enabled=false;              // klawisz Z
          if(Key==VK_UP) TimerP2G->Enabled=false;
          if(Key==VK_DOWN) TimerP2D->Enabled=false;
}
//---------------------------------------------------------------------------
