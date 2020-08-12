function drawFence numBoxes xpos ypos fenceColour direction = (
	delete objects
	start = box pos:[xpos,ypos,0] height: 40 length:5 width:5 wirecolor:fenceColour
	
	for i=0 to numBoxes-1 do (
		picket1 = box pos:[xpos+10+(50*i),ypos,0] height:38 length:5 width:5 wirecolor:fenceColour
		picket1.pivot = [xpos,ypos,0]
		rotate picket1 direction [0,0,1]
		picket2 = box pos:[xpos+20+(50*i),ypos,0] height:33 length:5 width:5 wirecolor:fenceColour
		picket2.pivot = [xpos,ypos,0]
		rotate picket2 direction [0,0,1]
		picket3 = box pos:[xpos+30+(50*i),ypos,0] height:30 length:5 width:5 wirecolor:fenceColour
		picket3.pivot = [xpos,ypos,0]
		rotate picket3 direction [0,0,1]
		picket4 = box pos:[xpos+40+(50*i),ypos,0] height:33 length:5 width:5 wirecolor:fenceColour
		picket4.pivot = [xpos,ypos,0]
		rotate picket4 direction [0,0,1]
		picket5 = box pos:[xpos+50+(50*i),ypos,0] height:38 length:5 width:5 wirecolor:fenceColour
		picket5.pivot = [xpos,ypos,0]
		rotate picket5 direction [0,0,1]
		end = box pos:[xpos+60+(50*i),ypos,0] height: 40 length:5 width:5 wirecolor:fenceColour
		end.pivot = [xpos,ypos,0]
		rotate end direction [0,0,1]

	)
	
	startEnd = (numBoxes)*50+10
	
	bottomPlank = box pos:[xpos+startEnd/2,ypos,5] height:3 width:startEnd length:1 wirecolor:fenceColour
	topPlank = box pos:[xpos+startEnd/2,ypos,20] height:3 width:startEnd length:1 wirecolor:fenceColour
	
	start.pivot = [xpos,ypos,0]
	
	rotate start direction [0,0,1]
	
	bottomPlank.pivot = [xpos,ypos,0]
	topPlank.pivot = [xpos,ypos,0]
	
	rotate bottomPlank direction [0,0,1]
	rotate topPlank direction [0,0,1]
	
)

try(destroyDialog myUIExample )catch()
rollout myUIExample "Fence Creator" (
	group "Controls" (
		spinner numSegmentsSpinner "Number of Segments:" type:#integer range:[1,100,10]
		spinner startLocationX "Starting X:" type:#float range:[-100,100,0]
		spinner startLocationY "Starting Y:" type:#float range:[-100,100,0]
		colorpicker fenceColourPicker "Fence Colour:"
		Angle fenceDirection "Direction: "
		button createBoxButton "Generate Fence"
	)
	on createBoxButton pressed do(
		drawFence numSegmentsSpinner.value startLocationX.value startLocationY.value fenceColourPicker.color fenceDirection.degrees
	)
)
createDialog myUIExample 400 400