Task:
	
	Create the graphical user interface using Qt for the application you are working on( see Laboratory 08 to 09).
		--windows are created from code, without window designers, drag & drop etc.

		Observer Pattern:
			-- create two different windows that present the contents of the prescription (PrescriptionCRUDGUI, PrescriptionReadOnlyGUI).

			   PrescriptionCRUDGUI - contains a list or table (items in the prescription) and buttons for emptying and generating a prescription.
			   PrescriptionReadOnlyGUI - uses drawing to show the number of items in the prescription. 
			                             A number of geometric figures or random images, equal to the medicine in the prescription, will appear 
							     on this window.

			 -- on application's main window: 
						-- add functionality that can add / delete / generate prescription content
						-- add 2 buttons that open basket windows (PrescriptionCRUDGUI, PrescriptionReadOnlyGUI).
						-- any change in the prescription must be automatically visible in all open windows.