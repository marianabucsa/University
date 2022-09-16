import React from 'react';
import './RoundApp.css'

class RoundForm extends React.Component {

    constructor(props) {
        super(props);
        this.state = {name: ''};
    }

    handleNameChange = (event) => {
        this.setState({name: event.target.value});
    };

    handleSubmit = (event) => {
        var round = {
            name: this.state.name
        };
        console.log(round);
        this.props.addFunc(round);
        event.preventDefault();
    };

    render() {
        return (
            <form id="roundForm" onSubmit={this.handleSubmit} >
                <label>
                    Name:&nbsp;&nbsp;
                    <input id="nameTxt" type="text" value={this.state.name} onChange={this.handleNameChange}/>
                </label><br/><br/>
                <input type="submit" value="Add" />
            </form>
        );
    }
}

export default RoundForm;