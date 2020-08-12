fn generatePath pathArray = (
	delete objects
	t = Track()
	for i=1 to pathArray.count do (
		if pathArray[i] == "left"
			then t.drawLeft()
		else if pathArray[i] == "Right"
			then t.drawRight()
		else if pathArray[i] == "Straight"
			then t.drawStraight()
	)
		
)

Struct Track(
	
	start = [0,0,0], -- start is where to start drawing board walk piece,
	position, -- positions is where pivot is to get each board rotated/bent
	heading = [0,1,0],
	headingQuat = quat 0 0 0 1,
	
	fn drawLeft = (
		b = box length:100 width:10 height:2 lengthsegs:10 widthsegs:1
		addmodifier b (bend())
		b.bend.bendangle = -45
		b.bend.bendAxis = 1		
	),
	fn drawRight = (
		c = box length:100 width:10 height:2 lengthsegs:10 widthsegs:1
		addmodifier c (bend())
		c.bend.bendangle = 45
		c.bend.bendAxis = 1	
	),
	fn drawStraight = (
		d = box length:100 width:10 height:2 lengthsegs:10 widthsegs:1

	)
)




 	thePath = #("left","left","left","left","left", "left", "left", "left")

 	generatePath thePath
