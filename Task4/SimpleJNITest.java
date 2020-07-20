package example_simple;
 
import java.util.ArrayList;
 
public class SimpleJNITest {
  ArrayList<String> values;
 
  public SimpleJNITest() {
    values = new ArrayList<String>();
   // System.out.println("entered java");
  }
 
  public void addValue(String v) {
    values.add(v);
  }
 
  public int getSize() {
    return values.size();
  }
 
  public void printValues() {
    for (String v: values) {
      System.out.println("Value : " + v);
    }
  }
  
  public void sleeping() {
        long start = System.currentTimeMillis();
        System.out.println("Start time in ms = " + start);
        try {
          Thread.sleep(2000);
        }
        catch (Exception e) {
        }
        long end = System.currentTimeMillis();
        System.out.println("End time in ms = " + end + " sleep time in ms = " + (end - start));
        
    }
}
