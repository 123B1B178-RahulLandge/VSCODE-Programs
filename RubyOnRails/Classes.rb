class Person
    def initialize(name)
      @name=name
    end 
    def func
      puts "Hello, #{@name}"
    end
    def func1(a,b)
      puts a+b
    end
  end
  
  p=Person.new("Abc")
  p.func
  p.func1(1,2)