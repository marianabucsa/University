import React from 'react';
import RoundTable from './RoundTable';
import './RoundApp.css'
import RoundForm from "./RoundForm";
import {GetRounds, DeleteRound, AddRound, UpdateRound} from './rest-calls'


class RoundApp extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      rounds: [{
        "name": "6666 m Round",
        "id": 3
      }],
      deleteFunc: this.deleteFunc.bind(this),
      addFunc: this.addFunc.bind(this),
      updateFunc: this.updateFunc.bind(this)
    };
    console.log('RoundApp constructor')
  }

  addFunc(round) {
    console.log('inside add Func ' + round);
    AddRound(round)
        .then(res => GetRounds())
        .then(rounds => this.setState({rounds}))
        .catch(error => console.log('Add error ', error));
  }

  updateFunc(round) {
    console.log('inside update Func ' + round);
    UpdateRound(round)
        .then(res => GetRounds())
        .then(rounds => this.setState({rounds}))
        .catch(error => console.log('Update error ', error));
  }


  deleteFunc(round) {
    console.log('inside deleteFunc ' + round);
    DeleteRound(round)
        .then(res => GetRounds())
        .then(rounds => this.setState({rounds}))
        .catch(error => console.log('Delete error', error));
  }


  componentDidMount() {
    console.log('inside componentDidMount');
    GetRounds().then(rounds => this.setState({rounds}));
  }

  render() {
    return (
        <div className="RoundApp">
          <h1>Rounds</h1>
          <RoundForm addFunc={this.state.addFunc}/>
          <br/>
          <br/>
          <RoundTable rounds={this.state.rounds.sort((a, b) => (a.id > b.id) ? 1 : -1)} deleteFunc={this.state.deleteFunc} updateFunc={this.state.updateFunc}/>
        </div>
    );
  }
}

export default RoundApp;