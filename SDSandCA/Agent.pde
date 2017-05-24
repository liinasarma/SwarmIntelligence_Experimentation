class Agent{

  int hypothesisX;
  int hypothesisY;
  boolean status;
  int _row1;
  int _row2;
  
  
  
Agent(){


}


void setHypoX(int hypoX)
{
    hypothesisX = hypoX; //return the agents hypothesis(column)
 
}

int getHypoX(){
    
    
    return hypothesisX;    //gte the selected agents hypothesis(column)
    
}
void setHypoY(int hypoY)
{
    hypothesisY = hypoY; //return the agents hypothesis(column)
}

int getHypoY(){
    
    
    return hypothesisY;    //gte the selected agents hypothesis(column)
    
}

void setRow1(int row1)
{
    _row1 = row1;
    
}
int row1()
{
    
    
    return _row1;
    
}

void setRow2(int row2)
{
    _row2 = row2;
    
  
    
}
int row2()
{
    
    
    return _row2;
    
}





void setStatus( boolean s )
{
    status = s;         //set status so that we know when symmetrical
}
boolean getStatus()
{
    
    return status;//returns the status if symmetrical
}





}