arr=["a","b","c"]
arr.each{|ar| puts ar}

person={name:"a",age:34}
person.each do |key,value|
  puts "#{key}:#{value}"
end

persons=[{name:"a",age:34},{name:"b",age:30},{name:"c",age:35}]
persons.each{|person| person.each do |key,value| puts "#{key}:#{value}" end}