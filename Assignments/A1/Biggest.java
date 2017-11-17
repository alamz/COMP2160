import java.io.*;

public class Biggest
{
    public static void main(String[] args)
    {
        BufferedReader fileIn;
        PrintWriter fileOut;
        String inputLine;
        String currWord = "";
        String bigWord = null;
        int bigWeight = 0;
        int weight = 0;
        int index;
        int line = 0;
        
        try
        {
            fileIn = new BufferedReader(new FileReader("in.txt"));
            fileOut = new PrintWriter(new FileWriter("out.txt"));
            
            inputLine = fileIn.readLine();
            while ( inputLine != null )
            {
                index = 0;
                line++;
                bigWord = null;
                bigWeight = 0;
                
                while (index < inputLine.length()) 
                {
                    weight = 0;
                    currWord = "";
                    while (index < inputLine.length() && 
                           (inputLine.charAt(index) != ' ' &&
                            inputLine.charAt(index) != '\t'))
                    {
                        currWord += inputLine.charAt(index);
                        weight += inputLine.charAt(index);
                        index++;
                    }
                    
                    if (weight > bigWeight)
                    {
                        bigWord = currWord;
                        bigWeight = weight;
                    }
                    
                    index++;
                }
                
                if (bigWord != null)
                {
                    fileOut.print( "line " + line + "'s word: " + bigWord );
                    fileOut.println();
                }
                
                inputLine = fileIn.readLine();
            }
            
            
            fileIn.close();
            fileOut.close();
        }
        
        catch (IOException ioe)
        {
            System.out.println(ioe.getMessage());
            ioe.printStackTrace();
        }
    }
}