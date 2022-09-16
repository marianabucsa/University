import React from 'react';
import {createRoot} from 'react-dom/client';
import './index.css';
import RoundApp from "./RoundApp"


const container=document.getElementById('root');
const root=createRoot(container);
root.render( <RoundApp/>);