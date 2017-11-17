public class Power
{
  static int count;
	
  public static void main( String[] args )
  {
    double[] base = { 1.4, 1.3, 1.2, 1.1 };
    int[]	   index = { 5, 20, 63, 73 };
    double   value;
    
    System.out.println( "\nTest two algorithms for powering\n" );
    for( int i=0 ; i<base.length ; i++ )
    {
      count = 0;
      value = power1( base[i], index[i] );
      System.out.println( "1: " + base[i] + "^" + index[i] + " = " + value + ", used " + count + " multiplies" );
      
      count = 0;
      value = power2( base[i], index[i] );
      System.out.println( "2: " + base[i] + "^" + index[i] + " = " + value + ", used " + count + " multiplies" );
      System.out.println();
    }
		
    System.out.println( "\nEnd of processing" );
  }
  
  public static double power1( double base, int index )
  {
    double retValue;
    
    if( index == 0 )
    {
      retValue = 1;
    }
    else
    {
      retValue = base * power1( base, index-1 );
      count++; 
    }
		
    return retValue;
  }
  
  public static double power2( double base, int index )
  {
    double retValue;
    double temp;
    
    if( index == 0 )
    { 
      retValue = 1;
    }
    else if( index%2 == 1 )
    {
      retValue = base * power2( base, index-1 );
      count++;
    }
    else
    {
      temp = power2( base, index/2 );
      retValue = temp*temp;
      count++;
    }
		
    return retValue;
  }
}
