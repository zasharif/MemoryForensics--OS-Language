import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

class Base
{
    protected static Scanner scan= new Scanner(System.in);
    protected static String text;
    
    public static String    SB1 = "Base:SB1:PublicStaticClassLevelString! \n";
    protected static String SB2 = "Base:SB2:ProtectedStaticClassLevelString! \n";
    private static String   SB3 = "Base:SB3:PrivateStaticClassLevelString! \n";

    public static void B1()
    {
        String S = "Base:B1():PublicStaticActiveMethodLevelString! \n";
        System.out.println("Base::public static B1() \n");
        B2();
    }

    protected static void B2()
    {
        String S = "Base:B2():ProtectedStaticActiveMethodLevelString! \n";
        System.out.println("Base::protected static B2() \n");
        B3();
    }

    private static void B3()
    {
        String S = "Base:B3():PrivateStaticActiveMethodLevelString! \n";
        String s1 = SB1;
        String s2 = SB2;
        String S3 = SB3;

        System.out.println("Base::private static B3():\n java_3.dump \n");
        text = scan.nextLine();
    }
    
    public static void    B11() { String S = "Base:B11():PublicStaticInActiveMethodLevelString! \n";    }
    protected static void B22() { String S = "Base:B22():ProtectedStaticInActiveMethodLevelString! \n"; }
    private static void   B33() { String S = "Base:B33():PrivateStaticInActiveMethodLevelString! \n";   }

    //----------------------------------------------------------------------------------------
    public String    sb1 = "Base:sb1:PublicInstanceLevelString! \n";
    protected String sb2 = "Base:sb2:ProtectedInstanceLevelString! \n";
    private String   sb3 = "Base:sb3:PrivateInstanceLevelString! \n";

    public void b1()
    {
        String S = "Base:b1():PublicInstanceActiveMethodLevelString! \n";
        System.out.println("Base::public instance b1() \n");
        b2();
    }

    protected void b2()
    {
        String S = "Base:b2():ProtectedInstanceActiveMethodLevelString! \n";
        System.out.println("Base::protected instance b2() \n");
        b3();
    }

    private void b3()
    {
        String S = "Base:b3():PrivateInstanceActiveMethodLevelString! \n";
        String s1 = sb1;
        String s2 = sb2;
        String S3 = sb3;
        System.out.println("Base::private instance b3():\n java_9.dump \n");
        text = scan.nextLine();
    }
    public void    b11() { String S = "Base:b11():PublicInstanceInActiveMethodLevelString! \n";    }
    protected void b22() { String S = "Base:b22():ProtectedInstanceInActiveMethodLevelString! \n"; }
    private void   b33() { String S = "Base:b33():PrivateInstanceInActiveMethodLevelString! \n";   }

    //----------------------------------------------------------------------------------------
    public void NotUsedVirtualFunc()
    {
        String S = "Base:NotUsedVirtualInstanceMethodLevelString! \n";
        System.out.println("Base::Override Public instance NotUsedVirtualFunc() \n");
        text = scan.nextLine();
    }
        
    public void usedVirtualFunc()
    {
        String S = "Base:UsedVirtualInstanceMethodLevelString! \n";
        System.out.println("Base::Override Public instance usedVirtualFunc() \n");
        text = scan.nextLine();
    }
}

class Derived1 extends Base
{

    public String    sd1 = "Derived1:sd1:PublicInstanceLevelString! \n";
    protected String sd2 = "Derived1:sd2:ProtectedInstanceLevelString! \n";
    private String   sd3 = "Derived1:sd3:PrivateInstanceLevelString! \n";
    
    public void NotUsedVirtualFunc()
    {
        String S = "Derived1:NotUsedVirtualInstanceMethodLevelString! \n";
        System.out.println("Derived1::Override Public instance NotUsedVirtualFunc() \n");
        text = scan.nextLine();
    }
        
    public void usedVirtualFunc()
    {
        String S = "Derived1:UsedVirtualInstanceMethodLevelString! \n";
        System.out.println("Derived1::Override Public instance usedVirtualFunc() \n");
        System.out.println("Derived1:: java_16.dump");
        text = scan.nextLine();
    }
    
   
    public void newFunc()
    {
        String S = "Derived1:newInstanceMethodLevelString! \n";
        System.out.println("Derived1::new Public instance method Func():\n java_13.dump \n");
        text = scan.nextLine(); 
    }
    
}


/**
 *
 * @author Ziad
 */
public class Program {
    static Scanner scan= new Scanner(System.in);
    static String text;
    
    public static void FF()
    {
        
    	String test1 = Base.SB1;
        System.out.println("FF(): java_2.dump");
        text = scan.nextLine();
        
        Base.B1();
        System.out.println("FF(): java_4.dump");
        text = scan.nextLine();
        
        Base BaseObj;
        System.out.println("FF(): java_5.dump");
        text = scan.nextLine();

        Derived1 DerivedObj;
        System.out.println("FF(): java_6.dump");
        text = scan.nextLine();
        
        BaseObj = new Base();
        System.out.println("FF(): java_7.dump");
        text = scan.nextLine();
        
        String test2 = BaseObj.sb1;
        System.out.println("FF(): java_8.dump");
        text = scan.nextLine();
        
        BaseObj.b1();          // dump_9 inside base.b1()
        System.out.println("FF(): java_10.dump");
        text = scan.nextLine();

        DerivedObj = new Derived1();
        System.out.println("FF(): java_11.dump");
        text = scan.nextLine();

        String test3 = DerivedObj.sd1;
        System.out.println("FF(): java_12.dump");
        text = scan.nextLine();
        
        DerivedObj.newFunc();  // dump_13 inside DerivedObj.newFunc()
        System.out.println("FF(): java_14.dump");
        text = scan.nextLine();
        
        Base upcastedObj = new Derived1();
        System.out.println("FF(): java_15.dump");
        text = scan.nextLine();

        upcastedObj.usedVirtualFunc(); // dump_16 inside DerivedObj.usedVirtualFunc()
        System.out.println("FF(): java_17.dump");
        text = scan.nextLine();
        
        upcastedObj = null;
        System.out.println("FF(): java_18.dump");
        text = scan.nextLine();
        
        DerivedObj = null;
        BaseObj = null;
        System.gc();
        
        System.out.println("FF(): java_19.dump");
        text = scan.nextLine();
    }
    
    
    public static void main(String[] args)
    {   
        System.out.println("Main(): java_1.dump");
        text = scan.nextLine();
        
        FF();
        System.out.println("Main(): java_20.dump");
        text = scan.nextLine();
       
     
        System.out.println("Main(): bye");
    }
}

// dump_21 after program termination
