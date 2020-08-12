function main = (
	delete objects;
	c1 = cone wirecolor:green pos:[-20,0,0] radius1:5
	c2 = cone wirecolor:blue pos:[0,0,0] radius1:5
	c3 = cone wirecolor:red pos:[20,0,0] radius1:5
	b = box length: 50 width:4 height:4
	
	rotate c1 30 [0,1,0]
	rotate c2 30 [0,-1,0]
	rotate c3 30 [1,1,1] 

	b.pivot=[0,-25,0]
	--move b [20,20,0]
	rotate b 45 [0,0,1]
)

main()